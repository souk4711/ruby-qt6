# frozen_string_literal: true

class TitlePage < RubyQt6::Bando::QWidget
  include LicenseWizardPage

  def initialize(wizard)
    super(wizard)
    initialize_page(wizard)

    @top_label = QLabel.new(tr('<center><font color="blue" size="5"><b><i> Super Product One</i></b></font></center>'))

    @register_radio_button = QRadioButton.new(tr('&Register your copy'))
    @evaluate_radio_button = QRadioButton.new(tr('&Evaluate our product'))
    set_focus_proxy(@register_radio_button)

    layout = QVBoxLayout.new
    layout.add_widget(@top_label)
    layout.add_spacing(10)
    layout.add_widget(@register_radio_button)
    layout.add_widget(@evaluate_radio_button)
    layout.add_stretch(1)
    set_layout(layout)
  end

  def reset_page
    @register_radio_button.set_checked true
  end

  def next_page
    @evaluate_radio_button.checked? ? @wizard.evaluate_page : @wizard.register_page
  end
end
