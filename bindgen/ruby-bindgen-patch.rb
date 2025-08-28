class RubyBindgen::Namer
  alias_method :_ruby, :ruby
  def ruby(cursor)
    if cursor.kind == :cursor_cxx_method
      if cursor.spelling.match(/^operator/)
        _ruby(cursor)
      else
        "_#{_ruby(cursor)}"
      end
    else
      _ruby(cursor)
    end
  end
end
