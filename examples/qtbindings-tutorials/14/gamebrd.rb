# frozen_string_literal: true

require 'qt6/all'
require_relative 'lcdrange'
require_relative 'cannon'

class GameBoard < RubyQt6::Bando::QWidget
  q_object do
    slot 'fire()'
    slot 'hit()'
    slot 'missed()'
    slot 'newGame()'
  end

  def initialize
    super

    quit = QPushButton.new('&Quit')
    quit.set_font(QFont.new('Times', 18, QFont::Bold))
    quit.clicked.connect($qApp, :quit)

    angle = LCDRange.new('ANGLE')
    force = LCDRange.new('FORCE')
    cannon_box = QFrame.new
    @cannon_field = CannonField.new(self)
    angle.set_range(5, 70)
    force.set_range(10, 50)
    cannon_box.set_frame_style(QFrame::WinPanel.to_i | QFrame::Sunken)
    angle.value_changed.connect(@cannon_field, :set_angle)
    force.value_changed.connect(@cannon_field, :set_force)
    @cannon_field.angle_changed.connect(angle, :set_value)
    @cannon_field.force_changed.connect(force, :set_value)
    @cannon_field.hit.connect(self, :hit)
    @cannon_field.missed.connect(self, :missed)

    shoot = QPushButton.new('&Shoot')
    shoot.set_font(QFont.new('Times', 18, QFont::Bold))
    shoot.clicked.connect(self, :fire)
    @cannon_field.can_shoot.connect(shoot, :setEnabled)

    restart = QPushButton.new('&New Game', self)
    restart.set_font(QFont.new('Times', 18, QFont::Bold))
    restart.clicked.connect(self, :newGame)

    @hits = QLCDNumber.new(2, self)
    @shots_left = QLCDNumber.new(2, self)
    hits_label = QLabel.new('HITS', self)
    shots_left_label = QLabel.new('SHOTS LEFT', self)

    QShortcut.new(QKeySequence.new(Qt::Key_Enter), self).activated.connect(self, :fire)
    QShortcut.new(QKeySequence.new(Qt::Key_Return), self).activated.connect(self, :fire)
    QShortcut.new(QKeySequence.new(Qt::CTRL.to_i + Qt::Key_Q.to_i), self).activated.connect(self, :close)

    top_layout = QHBoxLayout.new
    top_layout.add_widget(shoot)
    top_layout.add_widget(@hits)
    top_layout.add_widget(hits_label)
    top_layout.add_widget(@shots_left)
    top_layout.add_widget(shots_left_label)
    top_layout.add_stretch(1)
    top_layout.add_widget(restart)

    left_layout = QVBoxLayout.new
    left_layout.add_widget(angle)
    left_layout.add_widget(force)

    cannon_layout = QVBoxLayout.new
    cannon_layout.add_widget(@cannon_field)
    cannon_box.set_layout(cannon_layout)

    grid_layout = QGridLayout.new
    grid_layout.add_widget(quit, 0, 0)
    grid_layout.add_layout(top_layout, 0, 1)
    grid_layout.add_layout(left_layout, 1, 0)
    grid_layout.add_widget(cannon_box, 1, 1, 2, 1)
    grid_layout.set_column_stretch(1, 10)
    set_layout(grid_layout)

    angle.set_value(60)
    force.set_value(25)
    angle.set_focus

    new_game
  end

  def fire
    return if @cannon_field.game_over || @cannon_field.shooting?

    @shots_left.display(@shots_left.int_value - 1)
    @cannon_field.shoot
  end

  def hit
    @hits.display(@hits.int_value + 1)
    if @shots_left.int_value.zero?
      @cannon_field.set_game_over
    else
      @cannon_field.new_target
    end
  end

  def missed
    return unless @shots_left.int_value.zero?

    @cannon_field.set_game_over
  end

  def new_game
    @shots_left.display(15)
    @hits.display(0)
    @cannon_field.restart_game
    @cannon_field.new_target
  end
end
