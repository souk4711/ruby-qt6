# frozen_string_literal: true

class FinishPage < RubyQt6::Bando::QWidget
  include LicenseWizardPage

  def initialize(wizard)
    super(wizard)
    initialize_page(wizard)

    @top_label = QLabel.new(tr('<center><b>Complete your registration</b></center>'))

    @bottom_label = QLabel.new
    @bottom_label.set_word_wrap true

    @agree_checkbox = QCheckBox.new(tr('I agree to the terms and conditions of the license'))
    set_focus_proxy(@agree_checkbox)

    @agree_checkbox.toggled.connect(self, :complete_state_changed)

    layout = QVBoxLayout.new
    layout.add_widget(@top_label)
    layout.add_spacing(10)
    layout.add_widget(@bottom_label)
    layout.add_widget(@agree_checkbox)
    layout.add_stretch(1)
    set_layout(layout)
  end

  def reset_page
    license_text = if @wizard.history_pages.include? @wizard.evaluate_page
                     tr('Evaluation License Agreement: You can use self software for 30 days and make one back up, but you are not allowed to distribute it.')
                   elsif @wizard.history_pages.include? @wizard.details_page
                     tr('First-Time License Agreement: You can use self software subject to the license you will receive by email.')
                   else
                     tr('Upgrade License Agreement: This software is licensed under the terms of your current license.')
                   end
    @bottom_label.set_text license_text
    @agree_checkbox.set_checked false
  end

  def is_last_page
    true
  end

  def is_complete
    @agree_checkbox.checked?
  end
end
