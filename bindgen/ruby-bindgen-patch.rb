class FFI::Clang::Cursor
  def self.namer
    @namer || RubyBindgen::Namer.new(rename_predicate_method: false)
  end
end
