# frozen_string_literal: true

require_relative 'tetrixboard'

class TetrixWindow < RubyQt6::Bando::QWidget
  def initialize(parent = nil)
    super(parent)

    @board = TetrixBoard.new(self)

    @next_piece_label = QLabel.new
    @next_piece_label.set_frame_style QFrame::Box.to_i | QFrame::Raised
    @next_piece_label.set_alignment Qt::AlignCenter
    @board.next_piece_label = @next_piece_label

    @score_lcd = QLCDNumber.new(5)
    @score_lcd.set_segment_style QLCDNumber::Filled
    @level_lcd = QLCDNumber.new(2)
    @level_lcd.set_segment_style QLCDNumber::Filled
    @lines_lcd = QLCDNumber.new(5)
    @lines_lcd.set_segment_style QLCDNumber::Filled

    @start_button = QPushButton.new(tr('&Start'))
    @start_button.set_focus_policy Qt::NoFocus
    @quit_button = QPushButton.new(tr('&Quit'))
    @quit_button.set_focus_policy Qt::NoFocus
    @pause_button = QPushButton.new(tr('&Pause'))
    @pause_button.set_focus_policy Qt::NoFocus

    @start_button.clicked.connect(@board, :start)
    @quit_button.clicked.connect($qApp, :quit)
    @pause_button.clicked.connect(@board, :pause)
    @board.score_changed.connect(@score_lcd, :display)
    @board.level_changed.connect(@level_lcd, :display)
    @board.lines_removed_changed.connect(@lines_lcd, :display)

    layout = QGridLayout.new.tap do |l|
      l.add_widget(create_label(tr('NEXT')), 0, 0)
      l.add_widget(@next_piece_label, 1, 0)
      l.add_widget(create_label(tr('LEVEL')), 2, 0)
      l.add_widget(@level_lcd, 3, 0)
      l.add_widget(@start_button, 4, 0)
      l.add_widget(@board, 0, 1, 6, 1)
      l.add_widget(create_label(tr('SCORE')), 0, 2)
      l.add_widget(@score_lcd, 1, 2)
      l.add_widget(create_label(tr('LINES REMOVED')), 2, 2)
      l.add_widget(@lines_lcd, 3, 2)
      l.add_widget(@quit_button, 4, 2)
      l.add_widget(@pause_button, 5, 2)
    end
    set_layout(layout)

    set_window_title(tr('Tetrix'))
    resize(550, 370)
  end

  def create_label(text)
    lbl = QLabel.new(text)
    lbl.set_alignment Qt::AlignHCenter | Qt::AlignBottom
    lbl
  end
end
