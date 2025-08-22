class RubyBindgen::Namer
  alias_method :orig_initialize, :initialize
  def initialize(*, **)
    orig_initialize(*, **, rename_func_getter: true, rename_func_setter: true)
  end
end

class RubyBindgen::Visitors::Rice
  alias_method :orig_visit_translation_unit, :visit_translation_unit
  def visit_translation_unit(*, **)
    orig_visit_translation_unit(*, **, camelize_init_name: false)
  end
end
