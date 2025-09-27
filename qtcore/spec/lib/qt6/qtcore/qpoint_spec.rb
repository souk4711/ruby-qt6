RSpec.describe RubyQt6::QtCore::QPoint do
  it "#initialize" do
    o = described_class.new(1, 2)
    expect(o.x).to eq(1)
    expect(o.y).to eq(2)
  end

  it "#==" do
    expect(described_class.new(1, 2)).to eq(described_class.new(1, 2))
    expect(described_class.new(1, 2)).not_to eq(described_class.new(1, 3))

    expect(described_class.new(1, 2)).to eq(RubyQt6::QtCore::QPointF.new(1.0, 2.0))
    expect(described_class.new(1, 2)).not_to eq(RubyQt6::QtCore::QPointF.new(1.0, 2.1))

    expect(described_class.new(1, 2)).not_to eq(1)
    expect(described_class.new(1, 2)).not_to eq(nil)
  end
end
