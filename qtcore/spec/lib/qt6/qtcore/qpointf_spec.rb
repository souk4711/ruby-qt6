RSpec.describe RubyQt6::QtCore::QPointF do
  it "#initialize" do
    o = described_class.new(1.2, 3.4)
    expect(o.x).to eq(1.2)
    expect(o.y).to eq(3.4)
  end

  it "#==" do
    expect(described_class.new(1.0, 2.0)).to eq(described_class.new(1.0, 2.0))
    expect(described_class.new(1.0, 2.0)).not_to eq(described_class.new(1.0, 2.1))

    expect(described_class.new(1.0, 2.0)).to eq(RubyQt6::QtCore::QPoint.new(1, 2))
    expect(described_class.new(1.0, 2.0)).not_to eq(RubyQt6::QtCore::QPoint.new(1, 3))
  end
end
