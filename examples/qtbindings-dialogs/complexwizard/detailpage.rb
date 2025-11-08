# frozen_string_literal: true

class DetailsPage < RubyQt6::Bando::QWidget
  include LicenseWizardPage

  def initialize(wizard)
    super(wizard)
    initialize_page(wizard)

    @top_label = QLabel.new(tr('<center><b>Fill in your details</b></center>'))

    @company_label = QLabel.new(tr('&Company name:'))
    @company_line_edit = QLineEdit.new
    @company_label.set_buddy @company_line_edit
    set_focus_proxy(@company_line_edit)

    @email_label = QLabel.new(tr('&Email address:'))
    @email_line_edit = QLineEdit.new
    @email_label.set_buddy @email_line_edit

    @postal_label = QLabel.new(tr('&Postal address:'))
    @postal_line_edit = QLineEdit.new
    @postal_label.set_buddy @postal_line_edit

    @company_line_edit.text_changed.connect(self, :complete_state_changed)
    @email_line_edit.text_changed.connect(self, :complete_state_changed)
    @postal_line_edit.text_changed.connect(self, :complete_state_changed)

    layout = QGridLayout.new
    layout.add_widget(@top_label, 0, 0, 1, 2)
    layout.set_row_minimum_height(1, 10)
    layout.add_widget(@company_label, 2, 0)
    layout.add_widget(@company_line_edit, 2, 1)
    layout.add_widget(@email_label, 3, 0)
    layout.add_widget(@email_line_edit, 3, 1)
    layout.add_widget(@postal_label, 4, 0)
    layout.add_widget(@postal_line_edit, 4, 1)
    layout.set_row_stretch(5, 1)
    set_layout(layout)
  end

  def reset_page
    @company_line_edit.clear
    @email_line_edit.clear
    @postal_line_edit.clear
  end

  def next_page
    @wizard.finish_page
  end

  def is_complete
    !@company_line_edit.text.empty? && !@email_line_edit.text.empty? && !@postal_line_edit.text.empty?
  end
end
