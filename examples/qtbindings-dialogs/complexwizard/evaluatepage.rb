# frozen_string_literal: true

class EvaluatePage < RubyQt6::Bando::QWidget
  include LicenseWizardPage

  def initialize(wizard)
    super(wizard)
    initialize_page(wizard)

    @top_label = QLabel.new(tr('<center><b>Evaluate Super Product One</b></center>'))

    @name_label = QLabel.new(tr('&Name:'))
    @name_line_edit = QLineEdit.new
    @name_label.set_buddy @name_line_edit
    set_focus_proxy(@name_line_edit)

    @email_label = QLabel.new(tr('&Email address:'))
    @email_line_edit = QLineEdit.new
    @email_label.set_buddy @email_line_edit

    @bottom_label = QLabel.new(tr("Please fill in both fields.\nThis will entitle you to a 30-day evaluation."))

    @name_line_edit.text_changed.connect(self, :complete_state_changed)
    @email_line_edit.text_changed.connect(self, :complete_state_changed)

    layout = QGridLayout.new
    layout.add_widget(@top_label, 0, 0, 1, 2)
    layout.set_row_minimum_height(1, 10)
    layout.add_widget(@name_label, 2, 0)
    layout.add_widget(@name_line_edit, 2, 1)
    layout.add_widget(@email_label, 3, 0)
    layout.add_widget(@email_line_edit, 3, 1)
    layout.set_row_minimum_height(4, 10)
    layout.add_widget(@bottom_label, 5, 0, 1, 2)
    layout.set_row_stretch(6, 1)
    set_layout(layout)
  end

  def reset_page
    @name_line_edit.clear
    @email_line_edit.clear
  end

  def next_page
    @wizard.finish_page
  end

  def is_complete
    !@name_line_edit.text.empty? && !@email_line_edit.text.empty?
  end
end
