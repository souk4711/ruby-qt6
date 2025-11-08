# frozen_string_literal: true

require_relative 'licensewizardpage'
require_relative 'detailpage'
require_relative 'evaluatepage'
require_relative 'finishpage'
require_relative 'registerpage'
require_relative 'titlepage'

class LicenseWizard < RubyQt6::Bando::QDialog
  q_object do
    slot 'back_button_clicked()'
    slot 'next_button_clicked()'
    slot 'complete_state_changed()'
  end

  attr_accessor :title_page, :evaluate_page, :register_page, :details_page, :finish_page

  def initialize(parent = nil)
    super(parent)

    @history = []
    @cancel_button = QPushButton.new(tr('Cancel'))
    @back_button = QPushButton.new(tr('< &Back'))
    @next_button = QPushButton.new(tr('Next >'))
    @finish_button = QPushButton.new(tr('&Finish'))

    @cancel_button.clicked.connect(self, :reject)
    @back_button.clicked.connect(self, :back_button_clicked)
    @next_button.clicked.connect(self, :next_button_clicked)
    @finish_button.clicked.connect(self, :accept)

    @button_layout = QHBoxLayout.new
    @button_layout.add_stretch(1)
    @button_layout.add_widget(@cancel_button)
    @button_layout.add_widget(@back_button)
    @button_layout.add_widget(@next_button)
    @button_layout.add_widget(@finish_button)

    @main_layout = QVBoxLayout.new
    @main_layout.add_layout(@button_layout)
    set_layout(@main_layout)

    @title_page = TitlePage.new(self)
    @evaluate_page = EvaluatePage.new(self)
    @register_page = RegisterPage.new(self)
    @details_page = DetailsPage.new(self)
    @finish_page = FinishPage.new(self)

    set_first_page(@title_page)

    set_window_title(tr('Complex Wizard'))
    resize(480, 200)
  end

  def history_pages
    @history
  end

  def set_first_page(page)
    page.reset_page
    @history.push(page)
    switch_page(nil)
  end

  def back_button_clicked
    old_page = @history.pop
    old_page.reset_page
    switch_page(old_page)
  end

  def next_button_clicked
    old_page = @history.last
    new_page = old_page.next_page
    new_page.reset_page
    @history.push(new_page)
    switch_page(old_page)
  end

  def complete_state_changed
    current_page = @history.last
    if current_page.is_last_page
      @finish_button.set_enabled current_page.is_complete
    else
      @next_button.set_enabled current_page.is_complete
    end
  end

  def switch_page(old_page)
    if old_page
      old_page.hide
      old_page.complete_state_changed.disconnect(self, :complete_state_changed)
      @main_layout.remove_widget(old_page)
    end

    new_page = @history.last
    @main_layout.insert_widget(0, new_page)
    new_page.show
    new_page.set_focus
    new_page.complete_state_changed.connect(self, :complete_state_changed)

    @back_button.set_enabled @history.size != 1
    if new_page.is_last_page
      @next_button.set_enabled false
      @finish_button.set_default true
    else
      @next_button.set_default true
      @finish_button.set_enabled false
    end
    complete_state_changed
  end
end
