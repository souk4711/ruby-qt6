# frozen_string_literal: true

class RegisterPage < RubyQt6::Bando::QWidget
  include LicenseWizardPage

  def initialize(wizard)
    super(wizard)
    initialize_page(wizard)

    @top_label = QLabel.new(tr('<center><b>Register your copy of Super Product One</b></center>'))

    @name_label = QLabel.new(tr('&Name:'))
    @name_line_edit = QLineEdit.new
    @name_label.set_buddy @name_line_edit
    set_focus_proxy(@name_line_edit)

    @upgrade_key_label = QLabel.new(tr('&Upgrade key:'))
    @upgrade_key_line_edit = QLineEdit.new
    @upgrade_key_label.set_buddy @upgrade_key_line_edit

    @bottom_label = QLabel.new(tr('If you have an upgrade key, please fill in the appropriate field.'))

    @name_line_edit.text_changed.connect(self, :complete_state_changed)

    layout = QGridLayout.new
    layout.add_widget(@top_label, 0, 0, 1, 2)
    layout.set_row_minimum_height(1, 10)
    layout.add_widget(@name_label, 2, 0)
    layout.add_widget(@name_line_edit, 2, 1)
    layout.add_widget(@upgrade_key_label, 3, 0)
    layout.add_widget(@upgrade_key_line_edit, 3, 1)
    layout.set_row_minimum_height(4, 10)
    layout.add_widget(@bottom_label, 5, 0, 1, 2)
    layout.set_row_stretch(6, 1)
    set_layout(layout)
  end

  def reset_page
    @name_line_edit.clear
    @upgrade_key_line_edit.clear
  end

  def next_page
    @upgrade_key_line_edit.text.empty? ? @wizard.details_page : @wizard.finish_page
  end

  def is_complete
    !@name_line_edit.text.empty?
  end
end
