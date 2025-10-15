RSpec.describe RubyQt6::QtCore::QLine do
  it "#initialize" do
    o = described_class.new(1, 2, 3, 4)
    expect(o.x1).to eq(1)
    expect(o.y1).to eq(2)
    expect(o.x2).to eq(3)
    expect(o.y2).to eq(4)

    o = described_class.new(1, 2, 3.0, 4.0)
    expect(o.x1).to eq(1)
    expect(o.y1).to eq(2)
    expect(o.x2).to eq(3)
    expect(o.y2).to eq(4)

    p1 = RubyQt6::QtCore::QPoint.new(1, 2)
    p2 = RubyQt6::QtCore::QPoint.new(3, 4)
    o = described_class.new(p1, p2)
    expect(o.x1).to eq(1)
    expect(o.y1).to eq(2)
    expect(o.x2).to eq(3)
    expect(o.y2).to eq(4)
  end

  it "#==" do
    expect(described_class.new(1, 2, 3, 4)).to eq(described_class.new(1, 2, 3, 4))
    expect(described_class.new(1, 2, 3, 4)).not_to eq(described_class.new(1, 2, 3, 5))

    expect(described_class.new(1, 2, 3, 4)).to eq(RubyQt6::QtCore::QLineF.new(1.0, 2.0, 3.0, 4.0))
    expect(described_class.new(1, 2, 3, 4)).not_to eq(RubyQt6::QtCore::QLineF.new(1.0, 2.0, 3.0, 4.1))

    expect(described_class.new(1, 2, 3, 4)).not_to eq(1)
    expect(described_class.new(1, 2, 3, 4)).not_to eq(nil)
  end
end
