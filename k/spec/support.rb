module Support
  def self.self_and_descendants(klass)
    [klass].concat(descendants(klass)).sort_by(&:name)
  end

  def self.descendants(klass)
    _descendants(klass).filter { |k| !k.name.start_with?("RubyQt6::Bando") }
  end

  def self._descendants(klass)
    klass.subclasses.concat(klass.subclasses.flat_map { |k| _descendants(k) })
  end
  private_class_method :_descendants
end
