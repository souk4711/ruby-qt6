# frozen_string_literal: true

# @!visibility private
module ::Kernel
  def rubyqt6_include_constants(mod, enum)
    enum.constants.each do |const|
      mod.const_set(const, enum.const_get(const))
    end
  end
end
