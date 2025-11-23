# frozen_string_literal: true

# @!visibility private
class Object
  private

  def _gc_incref(object)
    self.class.__send__(:_gc_refs) << object
  end

  def self._gc_refs
    @_gc_refs ||= []
  end
  private_class_method :_gc_refs
end
