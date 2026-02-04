RSpec.describe QLineF do
  it "#initialize" do
    o = described_class.new(1, 2, 3, 4)
    expect(o.x1).to eq(1)
    expect(o.y1).to eq(2)
    expect(o.x2).to eq(3)
    expect(o.y2).to eq(4)

    p1 = QPointF.new(1, 2)
    p2 = QPointF.new(3, 4)
    o = described_class.new(p1, p2)
    expect(o.x1).to eq(1)
    expect(o.y1).to eq(2)
    expect(o.x2).to eq(3)
    expect(o.y2).to eq(4)
  end

  it "#==" do
    expect(described_class.new(1.0, 2.0, 3.0, 4.0)).to eq(described_class.new(1.0, 2.0, 3.0, 4.0))
    expect(described_class.new(1.0, 2.0, 3.0, 4.0)).not_to eq(described_class.new(1.0, 2.0, 3.0, 4.1))

    expect(described_class.new(1.0, 2.0, 3.0, 4.0)).to eq(QLine.new(1, 2, 3, 4))
    expect(described_class.new(1.0, 2.0, 3.0, 4.0)).not_to eq(QLine.new(1, 2, 3, 5))

    expect(described_class.new(1.0, 2.0, 3.0, 4.0)).not_to eq(1.0)
    expect(described_class.new(1.0, 2.0, 3.0, 4.0)).not_to eq(nil)
  end
end
