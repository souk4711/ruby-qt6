# frozen_string_literal: true

require_relative 'firstpage'
require_relative 'secondpage'
require_relative 'thirdpage'

class ClassWizard < RubyQt6::Bando::QDialog
  q_object do
    slot 'back_button_clicked()'
    slot 'next_button_clicked()'
    slot 'accept()'
  end

  attr_accessor :first_page, :second_page, :third_page

  def initialize(parent = nil)
    super(parent)

    @history = []
    @num_pages = 0
    @cancel_button = QPushButton.new(tr('Cancel'))
    @back_button = QPushButton.new(tr('< &Back'))
    @next_button = QPushButton.new(tr('Next >'))
    @finish_button = QPushButton.new(tr('&Finish'))

    @cancel_button.clicked.connect(self, :reject)
    @back_button.clicked.connect(self, :back_button_clicked)
    @next_button.clicked.connect(self, :next_button_clicked)
    @finish_button.clicked.connect(self, :accept)

    @button_layout = QHBoxLayout.new.tap do |b|
      b.add_stretch(1)
      b.add_widget(@cancel_button)
      b.add_widget(@back_button)
      b.add_widget(@next_button)
      b.add_widget(@finish_button)
    end

    @main_layout = QVBoxLayout.new.tap { |l| l.add_layout(@button_layout) }
    set_layout @main_layout

    set_num_pages(3)
  end

  def set_num_pages(n)
    @num_pages = n
    @history.push create_page(0)
    switch_page(nil)
  end

  def set_button_enabled(enable)
    if @history.length == @num_pages
      @finish_button.set_enabled enable
    else
      @next_button.set_enabled enable
    end
  end

  def back_button_clicked
    @next_button.set_enabled true
    @finish_button.set_enabled true

    old_page = @history.last
    switch_page(old_page)
  end

  def next_button_clicked
    @next_button.set_enabled true
    @finish_button.set_enabled(@history.length == @num_pages - 1)

    old_page = @history.last
    @history.push create_page(@history.length)
    switch_page(old_page)
  end

  def switch_page(old_page)
    unless old_page.nil?
      old_page.hide
      @main_layout.remove_widget(old_page)
    end

    new_page = @history.last
    @main_layout.insert_widget(0, new_page)
    new_page.show
    new_page.set_focus

    @back_button.set_enabled(@history.length != 1)
    if @history.length == @num_pages
      @next_button.set_enabled false
      @finish_button.set_default true
    else
      @next_button.set_default true
      @finish_button.set_enabled false
    end

    set_window_title(tr(format('Simple Wizard - Step %d of %d', @history.length, @num_pages)))
  end

  def create_page(index)
    case index
    when 0
      @first_page = FirstPage.new(self)
      return @first_page
    when 1
      @second_page = SecondPage.new(self)
      return @second_page
    when 2
      @third_page = ThirdPage.new(self)
      return @third_page
    end
    nil
  end

  def accept
    class_name = @first_page.class_name_line_edit.text
    base_class = @first_page.base_class_line_edit.text
    qobject_macro = @first_page.qobject_macro_checkbox.checked?
    qobject_ctor = @first_page.qobject_ctor_radio_button.checked?
    qwidget_ctor = @first_page.qwidget_ctor_radio_button.checked?
    default_ctor = @first_page.default_ctor_radio_button.checked?
    copy_ctor = @first_page.copy_ctor_checkbox.checked?

    comment = @second_page.comment_checkbox.checked?
    protect = @second_page.protect_checkbox.checked?
    mactor_name = @second_page.macro_name_line_edit.text
    include_base = @second_page.include_base_checkbox.checked?
    base_include = @second_page.base_include_line_edit.text

    outputDir = @third_page.output_dir_line_edit.text
    header = @third_page.header_line_edit.text
    implementation = @third_page.implementation_line_edit.text

    block = ''

    if comment
      block += "/*\n"
      block += "    #{header}\n"
      block += "*/\n"
      block += "\n"
    end
    if protect
      block += "#ifndef #{mactor_name}\n"
      block += "#define #{mactor_name}\n"
      block += "\n"
    end
    if include_base
      block += "#include #{base_include}\n"
      block += "\n"
    end

    block += "class #{class_name}"
    block += " : public #{base_class}" unless base_class.empty?
    block += "\n"
    block += "{\n"

    # qmake ignore Q_OBJECT

    if qobject_macro
      block += "    Q_OBJECT\n"
      block += "\n"
    end
    block += "public:\n"

    if qobject_ctor
      block += "    #{class_name}(QObject *parent);\n"
    elsif qwidget_ctor
      block += "    #{class_name}(QWidget *parent);\n"
    elsif default_ctor
      block += "    #{class_name}();\n"
      if copy_ctor
        block += "    #{class_name}(const #{class_name} &other);\n"
        block += "\n"
        block += "    #{class_name} &operator=(const #{class_name} &other);\n"
      end
    end
    block += "};\n"

    if protect
      block += "\n"
      block += "#endif\n"
    end

    header_file = QFile.new("#{outputDir}/#{header}")
    unless header_file.open(QFile::WriteOnly | QFile::Text)
      QMessageBox.warning(self, tr('Simple Wizard'),
                          tr(format("Cannot write file %s:\n%s", header_file.fileName, header_file.errorString)))
      return
    end

    header_file.write(block)

    block = ''

    if comment
      block += "/*\n"
      block += "    #{implementation}\n"
      block += "*/\n"
      block += "\n"
    end
    block += "#include \"#{header}\"\n"
    block += "\n"

    if qobject_ctor
      block += "#{class_name}::#{class_name}(QObject *parent)\n"
      block += "    : #{base_class}(parent)\n"
      block += "{\n"
      block += "}\n"
    elsif qwidget_ctor
      block += "#{class_name}::#{class_name}(QWidget *parent)\n"
      block += "    : #{base_class}(parent)\n"
      block += "{\n"
      block += "}\n"
    elsif default_ctor
      block += "#{class_name}::#{class_name}()\n"
      block += "{\n"
      block += "    // missing code\n"
      block += "}\n"

      if copy_ctor
        block += "\n"
        block += "#{class_name}::#{class_name}(const #{class_name} &other)\n"
        block += "{\n"
        block += "    *this = other;\n"
        block += "}\n"
        block += "\n"
        block += "#{class_name} &#{class_name}::operator=(const #{class_name} &other)\n"
        block += "{\n"
        block += "    #{base_class}::operator=(other);\n" unless base_class.empty?
        block += "    // missing code\n"
        block += "    return *this;\n"
        block += "}\n"
      end
    end

    implementation_file = QFile.new("#{outputDir}/#{implementation}")

    unless implementation_file.open(QFile::WriteOnly | QFile::Text)
      QMessageBox.warning(self, tr('Simple Wizard'),
                          tr(format("Cannot write file %s:\n%s", implementation_file.fileName, implementation_file.errorString)))
      return
    end

    implementation_file.write(block)

    super
  end
end
