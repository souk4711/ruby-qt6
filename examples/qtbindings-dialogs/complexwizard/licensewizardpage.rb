# frozen_string_literal: true

module LicenseWizardPage
  def self.included(mod)
    mod.class_exec do
      q_object do
        signal 'complete_state_changed()'
      end
    end
  end

  def initialize_page(wizard)
    @wizard = wizard
    hide
  end

  def reset_page
    nil
  end

  def next_page
    0
  end

  def is_last_page
    false
  end

  def is_complete
    true
  end
end
