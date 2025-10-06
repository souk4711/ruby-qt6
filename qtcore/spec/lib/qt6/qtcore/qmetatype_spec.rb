RSpec.describe RubyQt6::QtCore::QMetaType do
  it ".infer" do
    [
      [true, described_class::Type::Bool],
      [false, described_class::Type::Bool],
      [1234, described_class::Type::Int],
      [78.9, described_class::Type::Double],
      ["str", described_class::Type::QString],
      ["qstr", described_class::Type::QString],
      [RubyQt6::QtCore::QPoint.new(0, 0), described_class::Type::QPoint],
      [RubyQt6::QtCore::QPointF.new(0, 0), described_class::Type::QPointF],
      [RubyQt6::QtCore::QSize.new(0, 0), described_class::Type::QSize],
      [RubyQt6::QtCore::QSizeF.new(0, 0), described_class::Type::QSizeF]
    ].each do |(value, id)|
      o = described_class.infer(value)
      expect(o.id).to eq(id.to_i)
    end
  end
end
