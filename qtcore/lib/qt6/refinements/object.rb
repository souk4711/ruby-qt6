# frozen_string_literal: true

# @!visibility private
class Object
  def self._gc_refs
    @_gc_refs ||= []
  end

  def _gc_incref(object)
    self.class._gc_refs << object
  end
end
