class RubyBindgen::Namer
  alias_method :orig_ruby, :ruby
  def ruby(cursor)
    if cursor.kind == :cursor_cxx_method
      if cursor.spelling.match(/^[iI]s[A-Z_]/) && cursor.type.result_type.spelling == "bool"
        "#{cursor.spelling.underscore.sub(/^is_/, "")}?"
      elsif cursor.spelling.match(/^[sS]et[A-Z_]/) && cursor.num_arguments == 1
        "#{cursor.spelling.underscore.sub(/^set_/, "")}="
      elsif cursor.spelling.match(/^[gG]et[A-Z_]/) && cursor.num_arguments == 0
        cursor.spelling.underscore.sub(/^get_/, "").to_s
      else
        orig_ruby(cursor)
      end
    else
      orig_ruby(cursor)
    end
  end
end
