# frozen_string_literal: true

require_relative 'tetrixpiece'

class TetrixBoard < RubyQt6::Bando::QFrame
  q_object do
    signal 'score_changed(int)'
    signal 'level_changed(int)'
    signal 'lines_removed_changed(int)'
    slot 'start()'
    slot 'pause()'
  end

  BoardWidth = 10
  BoardHeight = 22

  def initialize(parent = nil)
    super(parent)

    set_frame_style(QFrame::Panel.to_i | QFrame::Sunken)
    set_focus_policy(Qt::StrongFocus)
    @is_starting = false
    @is_pasued = false
    @board = []
    clear_board

    @cur_piece = TetrixPiece.new
    @next_piece = TetrixPiece.new
    @next_piece.set_random_shape
    @timer = QBasicTimer.new
  end

  attr_writer :next_piece_label

  def shape_at(x, y)
    @board[(y * BoardWidth) + x]
  end

  def set_shape_at(x, y, shape)
    @board[(y * BoardWidth) + x] = shape
  end

  def timeout_time
    1000 / (1 + @level)
  end

  def square_width
    contents_rect.width / BoardWidth
  end

  def square_height
    contents_rect.height / BoardHeight
  end

  def size_hint
    QSize.new(BoardWidth * 15 + frame_width * 2, 15 + frame_width * 2)
  end

  def minimum_size_hint
    QSize.new(BoardWidth * 5 + frame_width * 2, 5 + frame_width * 2)
  end

  def start
    return if @is_pasued

    @is_starting = true
    @is_waiting_after_line = false
    @num_lines_removed = 0
    @num_pieces_dropped = 0
    @score = 0
    @level = 1
    clear_board

    lines_removed_changed.emit(@num_lines_removed)
    score_changed.emit(@score)
    level_changed.emit(@level)

    new_piece
    @timer.start(timeout_time, self)
  end

  def pause
    return unless @is_starting

    @is_pasued = !@is_pasued
    if @is_pasued
      @timer.stop
    else
      @timer.start(timeout_time, self)
    end
    update
  end

  def paint_event(e)
    _paint_event(e)

    painter = QPainter.new(self)
    rect = contents_rect

    if @is_pasued
      painter.draw_text(rect, Qt::AlignCenter, tr('Pause'))
      painter.end
      return
    end

    board_top = rect.bottom - BoardHeight * square_height

    (0...BoardHeight).each do |i|
      (0...BoardWidth).each do |j|
        shape = shape_at(j, BoardHeight - i - 1)
        if shape != TetrixPiece::NoShape
          draw_square(painter, rect.left + j * square_width, board_top + i * square_height, shape)
        end
      end
    end

    if @cur_piece.shape != TetrixPiece::NoShape
      (0...4).each do |i|
        x = @cur_x + @cur_piece.x(i)
        y = @cur_y - @cur_piece.y(i)
        draw_square(painter, rect.left + x * square_width, board_top + (BoardHeight - y - 1) * square_height,
                    @cur_piece.shape)
      end
    end
    painter.end
  end

  def key_press_event(event)
    if !@is_starting || @is_pasued || @cur_piece.shape == TetrixPiece::NoShape
      _key_press_event(event)
      return
    end

    case Qt::Key.from_int(event.key)
    when Qt::Key_Left
      try_move(@cur_piece, @cur_x - 1, @cur_y)
    when Qt::Key_Right
      try_move(@cur_piece, @cur_x + 1, @cur_y)
    when Qt::Key_Down
      try_move(@cur_piece.rotated_right, @cur_x, @cur_y)
    when Qt::Key_Up
      try_move(@cur_piece.rotated_left, @cur_x, @cur_y)
    when Qt::Key_Space
      drop_down
    when Qt::Key_D
      one_line_down
    else
      _key_press_event(event)
    end
  end

  def timer_event(event)
    if event.timer_id == @timer.timer_id
      if @is_waiting_after_line
        @is_waiting_after_line = false
        new_piece
        @timer.start(timeout_time, self)
      else
        one_line_down
      end
    else
      _timer_event(event)
    end
  end

  def clear_board
    (0...BoardWidth * BoardHeight).each do |i|
      @board[i] = TetrixPiece::NoShape
    end
  end

  def drop_down
    drop_height = 0
    new_y = @cur_y
    while new_y.positive?
      break unless try_move(@cur_piece, @cur_x, new_y - 1)

      new_y -= 1
      drop_height += 1
    end
    piece_dropped(drop_height)
  end

  def one_line_down
    return if try_move(@cur_piece, @cur_x, @cur_y - 1)

    piece_dropped(0)
  end

  def piece_dropped(drop_height)
    (0...4).each do |i|
      x = @cur_x + @cur_piece.x(i)
      y = @cur_y - @cur_piece.y(i)
      set_shape_at(x, y, @cur_piece.shape)
    end

    @num_pieces_dropped += 1
    if (@num_pieces_dropped % 25).zero?
      @level += 1
      @timer.start(timeout_time, self)
      level_changed.emit(@level)
    end

    @score += drop_height + 7
    score_changed.emit(@score)
    remove_full_lines

    return if @is_waiting_after_line

    new_piece
  end

  def remove_full_lines
    num_full_lines = 0
    (BoardHeight - 1).downto(0) do |i|
      line_is_full = true

      (0...BoardWidth).each do |j|
        if shape_at(j, i) == TetrixPiece::NoShape
          line_is_full = false
          break
        end
      end

      next unless line_is_full

      num_full_lines += 1
      (i...BoardHeight).each do |k|
        (0...BoardWidth).each do |j|
          set_shape_at(j, k, shape_at(j, k + 1))
        end
      end
      (0...BoardWidth).each do |j|
        set_shape_at(j, BoardHeight - 1, TetrixPiece::NoShape)
      end
    end

    return unless num_full_lines.positive?

    @num_lines_removed += num_full_lines
    @score += 10 * num_full_lines
    lines_removed_changed.emit(@num_lines_removed)
    score_changed.emit(@score)

    @timer.start(500, self)
    @is_waiting_after_line = true
    @cur_piece.shape = TetrixPiece::NoShape
    update
  end

  def new_piece
    @cur_piece = @next_piece
    @next_piece.set_random_shape
    show_next_piece
    @cur_x = BoardWidth / 2 + 1
    @cur_y = BoardHeight - 1 + @cur_piece.min_y

    return if try_move(@cur_piece, @cur_x, @cur_y)

    @cur_piece.shape = TetrixPiece::NoShape
    @timer.stop
    @is_starting = false
  end

  def show_next_piece
    return if @next_piece_label.nil?

    dx = @next_piece.max_x - @next_piece.min_x + 1
    dy = @next_piece.max_y - @next_piece.min_y + 1

    pixmap = QPixmap.new(dx * square_width, dy * square_height)
    painter = QPainter.new(pixmap)
    painter.fill_rect(pixmap.rect, @next_piece_label.palette.window)

    (0...4).each do |i|
      x = @next_piece.x(i) - @next_piece.min_x
      y = @next_piece.y(i) - @next_piece.min_y
      draw_square(painter, x * square_width, y * square_height, @next_piece.shape)
    end
    @next_piece_label.set_pixmap pixmap
    painter.end
  end

  def try_move(new_piece, new_x, new_y)
    (0...4).each do |i|
      x = new_x + new_piece.x(i)
      y = new_y - new_piece.y(i)
      return false if x.negative? || x >= BoardWidth || y.negative? || y >= BoardHeight
      return false if shape_at(x, y) != TetrixPiece::NoShape
    end

    @cur_piece = new_piece
    @cur_x = new_x
    @cur_y = new_y
    update
    true
  end

  def draw_square(painter, x, y, shape)
    color_table = [0x000000, 0xCC6666, 0x66CC66, 0x6666CC, 0xCCCC66, 0xCC66CC, 0x66CCCC, 0xDAAA00]
    color = QColor.from_rgb(color_table[shape])
    painter.fill_rect(x + 1, y + 1, square_width - 2, square_height - 2, QBrush.new(color))

    painter.set_pen color.lighter
    painter.draw_line(x, y + square_height - 1, x, y)
    painter.draw_line(x, y, x + square_width - 1, y)

    painter.set_pen color.darker
    painter.draw_line(x + 1, y + square_height - 1, x + square_width - 1, y + square_height - 1)
    painter.draw_line(x + square_width - 1, y + square_height - 1, x + square_width - 1, y + 1)
  end
end
