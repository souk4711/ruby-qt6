require 'qt6/all'

class CannonField < RubyQt6::Bando::QWidget
  q_object do
    signal 'hit()'
    signal 'missed()'
    signal 'angleChanged(int)'
    signal 'forceChanged(int)'
    signal 'canShoot(bool)'
    slot 'setAngle(int)'
    slot 'setForce(int)'
    slot 'shoot()'
    slot 'moveShot()'
    slot 'newTarget()'
    slot 'setGameOver()'
    slot 'restartGame()'
  end

  def initialize(parent = nil)
    super

    @current_angle = 45
    @current_force = 0
    @timer_count = 0
    @auto_shoot_timer = QTimer.new(self)
    @auto_shoot_timer.timeout.connect(self, :moveShot)

    @shoot_angle = 0
    @shoot_force = 0
    set_palette(QPalette.new(QColor.new(250, 250, 200)))
    set_auto_fill_background(true)

    @game_ended = false
    @barrel_pressed = false
    @barrel_rect = QRect.new(30, -5, 20, 10)
    @target = QPoint.new(0, 0)
    new_target
  end

  def game_over
    @game_ended
  end

  def set_angle(degrees)
    degrees = 5 if degrees < 5
    degrees = 70 if degrees > 70
    return if @current_angle == degrees

    @current_angle = degrees
    update(cannon_rect)
    angle_changed.emit(@current_angle)
  end

  def set_force(newton)
    newton = 0 if newton < 0
    return if @currentForce == newton

    @current_force = newton
    force_changed.emit(@current_force)
  end

  def shoot
    return if shooting?

    @timer_count = 0
    @shoot_angle = @current_angle
    @shoot_force = @current_force
    @auto_shoot_timer.start(50)
    can_shoot.emit(false)
  end

  @@first_time = true
  def new_target
    if @@first_time
      @@first_time = false
      midnight = QTime.new(0, 0, 0)
      srand(midnight.secs_to(QTime.current_time))
    end

    @target = QPoint.new(200 + rand(190), 10 + rand(255))
    update
  end

  def set_game_over
    return if @game_ended
    @auto_shoot_timer.stop if shooting?
    @game_ended = true
    update
  end

  def restart_game
    @auto_shoot_timer.stop if shooting?
    @game_ended = false
    update
    can_shoot.emit(true)
  end

  def move_shot
    r = QRegion.new(shot_rect)
    @timer_count += 1

    shot_r = shot_rect
    if shot_r.intersects(target_rect)
      @auto_shoot_timer.stop
      hit.emit
      can_shoot.emit(true)
    elsif shot_r.x > width || shot_r.y > height || shot_r.intersects(barrel_rect)
      @auto_shoot_timer.stop
      missed.emit
      can_shoot.emit(true)
    else
      r = r.united(QRegion.new(shot_r))
    end

    update(r)
  end

  def mouse_press_event(e)
    return if e.button != Qt::LeftButton
    @barrel_pressed = true if barrel_hit(e.position)
  end

  def mouse_move_event(e)
    return unless @barrel_pressed
    pnt = e.position
    pnt.set_x(1) if pnt.x <= 0
    pnt.set_y(height - 1) if pnt.y >= height
    rad = Math.atan2((rect.bottom - pnt.y), pnt.x)
    set_angle((rad * 180 / 3.14159265).round)
  end

  def mouse_release_event(e)
    @barrel_pressed = false if e.button == Qt::LeftButton
  end

  def paint_event(e)
    p = QPainter.new(self)
    if @game_ended
      p.set_pen(QColor.new(Qt::Black))
      p.set_font(QFont.new("Courier", 48, QFont::Bold))
      p.draw_text(rect, Qt::AlignCenter, "Game Over")
    end
    paint_cannon(p)
    paint_barrel(p)
    paint_shot(p) if shooting?
    paint_target(p) unless @game_ended
    p.end
  end

  def paint_shot(p)
    p.set_pen(Qt::NoPen)
    p.set_brush(QBrush.new(Qt::Black))
    p.draw_rect(shot_rect)
  end

  def paint_target(painter)
    painter.set_brush(QBrush.new(Qt::Red))
    painter.set_pen(QPen.new(QColor.new(Qt::Black)))
    painter.draw_rect(target_rect)
  end

  def paint_barrel(painter)
    painter.set_brush(QBrush.new(Qt::Yellow))
    painter.set_pen(QColor.new(Qt::Black))
    painter.draw_rect(barrel_rect)
  end

  def paint_cannon(painter)
    painter.set_pen(Qt::NoPen)
    painter.set_brush(QBrush.new(Qt::Blue))

    painter.save
    painter.translate(0, height)
    painter.draw_pie(QRect.new(-35, -35, 70, 70), 0, 90 * 16)
    painter.rotate(- @current_angle)
    painter.draw_rect(@barrel_rect)
    painter.restore
  end

  def cannon_rect
    r = QRect.new(0, 0, 50, 50)
    r.move_bottom_left(rect.bottom_left)
    return r
  end

  def shot_rect
    gravity = 4.0

    time      = @timer_count / 4.0
    velocity  = @shoot_force
    radians   = @shoot_angle * 3.14159265 / 180.0

    velx      = velocity * Math.cos(radians)
    vely      = velocity * Math.sin(radians)
    x0        = (@barrel_rect.right  + 5.0) * Math.cos(radians)
    y0        = (@barrel_rect.right  + 5.0) * Math.sin(radians)
    x         = x0 + velx * time
    y         = y0 + vely * time - 0.5 * gravity * time * time

    r = QRect.new(0, 0, 6, 6);
    r.move_center(QPoint.new(x.round, height - 1 - y.round))
    r
  end

  def target_rect
    r = QRect.new(0, 0, 20, 10)
    r.move_center(QPoint.new(@target.x, height - 1 - @target.y));
    r
  end

  def barrel_rect
    QRect.new(145, height - 100, 15, 99)
  end

  def barrel_hit(pos)
    matrix = QTransform.new
    matrix.translate(0, height)
    matrix.rotate(- @current_angle)
    matrix = matrix.inverted
    @barrel_rect.contains(matrix.map(pos.to_point))
  end

  def shooting?
    @auto_shoot_timer.active?
  end
end
