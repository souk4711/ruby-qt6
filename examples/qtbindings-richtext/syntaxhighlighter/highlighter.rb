# frozen_string_literal: true

class Highlighter < RubyQt6::Bando::QObject
  q_object do
    slot 'highlight(int,int,int)'
  end

  def initialize(parent = nil)
    super(parent)
    @mappings = {}
  end

  def add_to_document(doc)
    doc.contents_change.connect(self, :highlight)
  end

  def add_mapping(pattern, format)
    @mappings[pattern] = format
  end

  def highlight(position, removed, added)
    doc = sender

    block = doc.find_block(position)
    return unless block.valid?

    end_block = if added > removed
                  doc.find_block(position + added)
                else
                  block
                end

    while block.valid? && block != end_block
      highlight_block(block)
      block = block.next
    end
  end

  def highlight_block(block)
    layout = block.layout
    text = block.text
    return if text.empty?

    overrides = []
    @mappings.each do |pattern, value|
      expression = QRegularExpression.new(pattern)
      iter = expression.global_match(text)
      while iter.has_next
        match = iter.next
        captured = match.captured(0)
        range = QTextLayout::FormatRange.new
        range.start = match.captured_start
        range.length = captured.length
        range.format = value
        overrides << range
      end
    end

    layout.set_formats(*overrides)
    block.document.mark_contents_dirty(block.position, block.length)
  end
end
