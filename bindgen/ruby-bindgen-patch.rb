class FFI::Clang::Cursor
  def self.namer
    @namer || RubyBindgen::Namer.new(rename_predicate_method: false)
  end
end

class RubyBindgen::Visitors::Rice
  alias_method :orig_visit_translation_unit, :visit_translation_unit

  # rubocop:disable Lint/DuplicateMethods
  def visit_translation_unit(*, **)
    orig_visit_translation_unit(*, **, camelize_init_name: false)
  end
  # rubocop:enable Lint/DuplicateMethods
end
