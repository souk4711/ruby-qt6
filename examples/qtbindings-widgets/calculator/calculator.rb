# frozen_string_literal: true

require_relative 'button'

class Calculator < RubyQt6::Bando::QDialog
  NUM_DIGITS_BUTTONS = 10

  q_object do
    slot 'digit_clicked(QString)'
    slot 'unary_operator_clicked(QString)'
    slot 'additive_operator_clicked(QString)'
    slot 'multiplicative_opertor_clicked(QString)'
    slot 'equal_clicked()'
    slot 'point_clicked()'
    slot 'change_sign_clicked()'
    slot 'backspace_clicked()'
    slot 'clear()'
    slot 'clear_all()'
    slot 'clear_memory()'
    slot 'read_memory()'
    slot 'set_memory()'
    slot 'add_to_memory()'
  end

  def initialize(parent = nil)
    super(parent)

    @sum_in_memory = 0.0
    @sum_so_far = 0.0
    @factor_so_far = 0.0
    @waiting_for_operand = true

    @display = QLineEdit.new('0')
    @display.set_read_only true
    @display.set_alignment Qt::AlignRight.to_qflags
    @display.set_max_length 15

    font = @display.font
    font.set_point_size font.point_size + 8
    @display.set_font font

    digit_color = QColor.new(150, 205, 205)
    backspace_color = QColor.new(225, 185, 135)
    memory_color = QColor.new(100, 155, 155)
    operator_color = QColor.new(155, 175, 195)

    @digit_buttons = []
    (0...NUM_DIGITS_BUTTONS).each { |i| @digit_buttons[i] = create_button(i.to_s, digit_color) }
    @point_button = create_button(tr('.'), digit_color, :point_clicked)
    @change_sign_button = create_button(tr('+/-'), digit_color, :change_sign_clicked)

    @backspace_button = create_button(tr('Backspace'), backspace_color, :backspace_clicked)
    @clear_button = create_button(tr('Clear'), backspace_color, :clear)
    @clear_all_button = create_button(tr('Clear All'), backspace_color.lighter(120), :clear_all)

    @clear_memory_button = create_button(tr('MC'), memory_color, :clear_memory)
    @read_memory_button = create_button(tr('MR'), memory_color, :read_memory)
    @set_memory_button = create_button(tr('MS'), memory_color, :set_memory)
    @add_to_memory_button = create_button(tr('M+'), memory_color, :add_to_memory)

    @division_button = create_button(tr('/'), operator_color)
    @times_button = create_button(tr('*'), operator_color)
    @minus_button = create_button(tr('-'), operator_color)
    @plus_button = create_button(tr('+'), operator_color)

    @square_root_button = create_button(tr('sqrt'), operator_color)
    @power_button = create_button(tr('x^2'), operator_color)
    @reciprocal_button = create_button(tr('1/x'), operator_color)
    @equal_button = create_button(tr('='), operator_color.lighter(120), :equal_clicked)

    @signal_mapper_digit_clicked = QSignalMapper.new(self)
    @signal_mapper_additive_operator_clicked = QSignalMapper.new(self)
    @signal_mapper_multiplicative_opertor_clicked = QSignalMapper.new(self)
    @signal_mapper_unary_operator_clicked = QSignalMapper.new(self)

    (0...NUM_DIGITS_BUTTONS).each do |i|
      @digit_buttons[i].clicked.connect(@signal_mapper_digit_clicked, :map)
      @signal_mapper_digit_clicked.set_mapping(@digit_buttons[i], i.to_s)
    end
    @signal_mapper_digit_clicked.mapped_string.connect(self, :digit_clicked)

    @division_button.clicked.connect(@signal_mapper_multiplicative_opertor_clicked, :map)
    @times_button.clicked.connect(@signal_mapper_multiplicative_opertor_clicked, :map)
    @signal_mapper_multiplicative_opertor_clicked.set_mapping(@division_button, '/')
    @signal_mapper_multiplicative_opertor_clicked.set_mapping(@times_button, '*')
    @signal_mapper_multiplicative_opertor_clicked.mapped_string.connect(self, :multiplicative_opertor_clicked)

    @minus_button.clicked.connect(@signal_mapper_additive_operator_clicked, :map)
    @plus_button.clicked.connect(@signal_mapper_additive_operator_clicked, :map)
    @signal_mapper_additive_operator_clicked.set_mapping(@minus_button, '-')
    @signal_mapper_additive_operator_clicked.set_mapping(@plus_button, '+')
    @signal_mapper_additive_operator_clicked.mapped_string.connect(self, :additive_operator_clicked)

    @square_root_button.clicked.connect(@signal_mapper_unary_operator_clicked, :map)
    @power_button.clicked.connect(@signal_mapper_unary_operator_clicked, :map)
    @reciprocal_button.clicked.connect(@signal_mapper_unary_operator_clicked, :map)
    @signal_mapper_unary_operator_clicked.set_mapping(@square_root_button, 'sqrt')
    @signal_mapper_unary_operator_clicked.set_mapping(@power_button, 'x^2')
    @signal_mapper_unary_operator_clicked.set_mapping(@reciprocal_button, '1/x')
    @signal_mapper_unary_operator_clicked.mapped_string.connect(self, :unary_operator_clicked)

    main_layout = QGridLayout.new
    main_layout.set_size_constraint QLayout::SetFixedSize

    main_layout.add_widget(@display, 0, 0, 1, 6)
    main_layout.add_widget(@backspace_button, 1, 0, 1, 2)
    main_layout.add_widget(@clear_button, 1, 2, 1, 2)
    main_layout.add_widget(@clear_all_button, 1, 4, 1, 2)

    main_layout.add_widget(@clear_memory_button, 2, 0)
    main_layout.add_widget(@read_memory_button, 3, 0)
    main_layout.add_widget(@set_memory_button, 4, 0)
    main_layout.add_widget(@add_to_memory_button, 5, 0)

    (1...NUM_DIGITS_BUTTONS).each do |i|
      row = ((9 - i) / 3) + 2
      column = ((i - 1) % 3) + 1
      main_layout.add_widget(@digit_buttons[i], row, column)
    end

    main_layout.add_widget(@digit_buttons[0], 5, 1)
    main_layout.add_widget(@point_button, 5, 2)
    main_layout.add_widget(@change_sign_button, 5, 3)

    main_layout.add_widget(@division_button, 2, 4)
    main_layout.add_widget(@times_button, 3, 4)
    main_layout.add_widget(@minus_button, 4, 4)
    main_layout.add_widget(@plus_button, 5, 4)

    main_layout.add_widget(@square_root_button, 2, 5)
    main_layout.add_widget(@power_button, 3, 5)
    main_layout.add_widget(@reciprocal_button, 4, 5)
    main_layout.add_widget(@equal_button, 5, 5)
    set_layout(main_layout)

    set_window_title(tr('Calculator'))
  end

  def digit_clicked(text)
    digit_value = text.to_s.to_i
    return if @display.text == '0' && digit_value.zero?

    if @waiting_for_operand
      @display.clear
      @waiting_for_operand = false
    end
    @display.set_text "#{@display.text}#{digit_value}"
  end

  def unary_operator_clicked(text)
    clicked_operator = text
    operand = @display.text.to_s.to_f
    result

    if clicked_operator == tr('sqrt')
      if operand < 0.0
        abort_operation
        return
      end
      result = Math.sqrt(operand)
    elsif clicked_operator == tr('x^2')
      result = operand**2.0
    elsif clicked_operator == tr('1/x')
      if operand == 0.0
        abort_operation
        return
      end
      result = 1.0 / operand
    end
    @display.set_text result.to_s
    @waiting_for_operand = true
  end

  def additive_operator_clicked(text)
    clicked_operator = text
    operand = @display.text.to_s.to_f

    unless @pending_multiplicative_operator.nil?
      unless calculate(operand, @pending_multiplicative_operator)
        abort_operation
        return
      end
      @display.set_text @factor_so_far.to_s
      operand = @factor_so_far
      @factor_so_far = 0.0
      @pending_multiplicative_operator = nil
    end

    if !@pending_additive_operator.nil?
      unless calculate(operand, @pending_additive_operator)
        abort_operation
        return
      end
      @display.set_text @sum_so_far.to_s
    else
      @sum_so_far = operand
    end

    @pending_additive_operator = clicked_operator
    @waiting_for_operand = true
  end

  def multiplicative_opertor_clicked(text)
    clicked_operator = text
    operand = @display.text.to_s.to_f

    if !@pending_multiplicative_operator.nil?
      unless calculate(operand, @pending_multiplicative_operator)
        abort_operation
        return
      end
      @display.set_text @factor_so_far.to_s
    else
      @factor_so_far = operand
    end

    @pending_multiplicative_operator = clicked_operator
    @waiting_for_operand = true
  end

  def equal_clicked
    operand = @display.text.to_s.to_f

    unless @pending_multiplicative_operator.nil?
      unless calculate(operand, @pending_multiplicative_operator)
        abort_operation
        return
      end
      operand = @factor_so_far
      @factor_so_far = 0.0
      @pending_multiplicative_operator = nil
    end
    if !@pending_additive_operator.nil?
      unless calculate(operand, @pending_additive_operator)
        abort_operation
        return
      end
      @pending_additive_operator = nil
    else
      @sum_so_far = operand
    end

    @display.set_text @sum_so_far.to_s
    @sum_so_far = 0.0
    @waiting_for_operand = true
  end

  def point_clicked
    @display.set_text '0' if @waiting_for_operand
    @display.set_text "#{@display.text}#{tr('.')}" unless @display.text.to_s.include? '.'
    @waiting_for_operand = false
  end

  def change_sign_clicked
    text = @display.text.to_s
    value = text.to_f

    if value > 0.0
      text.insert(0, tr('-'))
    elsif value < 0.0
      set_text text[1, text.length - 1]
    end
    @display.set_text text
  end

  def backspace_clicked
    return if @waiting_for_operand

    text = @display.text.to_s
    text.chop!
    if text.empty?
      text = '0'
      @waiting_for_operand = true
    end
    @display.set_text text
  end

  def clear
    return if @waiting_for_operand

    @display.set_text '0'
    @waiting_for_operand = true
  end

  def clear_all
    @sum_so_far = 0.0
    @factor_so_far = 0.0
    @pending_additive_operator = nil
    @pending_multiplicative_operator = nil
    @display.set_text '0'
    @waiting_for_operand = true
  end

  def clear_memory
    @sum_in_memory = 0.0
  end

  def read_memory
    @display.set_text @sum_in_memory.to_s
    @waiting_for_operand = true
  end

  def set_memory
    equal_clicked
    @sum_in_memory = @display.text.to_s.to_f
  end

  def add_to_memory
    equal_clicked
    @sum_in_memory += @display.text.to_s.to_f
  end

  def create_button(text, color, member = nil)
    button = CalcButton.new(text, color)
    button.clicked.connect(self, member) if member
    button
  end

  def abort_operation
    clear_all
    @display.set_text tr('####')
  end

  def calculate(right_operand, pending_operator)
    if pending_operator == tr('+')
      @sum_so_far += right_operand
    elsif pending_operator == tr('-')
      @sum_so_far -= right_operand
    elsif pending_operator == tr('*')
      @factor_so_far *= right_operand
    elsif pending_operator == tr('/')
      return false if right_operand == 0.0

      @factor_so_far /= right_operand
    end
    true
  end
end
