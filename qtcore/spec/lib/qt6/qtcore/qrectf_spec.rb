RSpec.describe QRectF do
  it "#initialize" do
    o = described_class.new(1, 2, 3, 4)
    expect(o.x).to eq(1)
    expect(o.y).to eq(2)
    expect(o.width).to eq(3)
    expect(o.height).to eq(4)

    p1 = QPointF.new(1, 2)
    p2 = QPointF.new(3, 4)
    o = described_class.new(p1, p2)
    expect(o.top_left).to eq(p1)
    expect(o.bottom_right).to eq(p2)
  end

  it "#==" do
    expect(described_class.new(1.0, 2.0, 3.0, 4.0)).to eq(described_class.new(1.0, 2.0, 3.0, 4.0))
    expect(described_class.new(1.0, 2.0, 3.0, 4.0)).not_to eq(described_class.new(1.0, 2.0, 3.0, 4.1))

    expect(described_class.new(1.0, 2.0, 3.0, 4.0)).to eq(QRect.new(1, 2, 3, 4))
    expect(described_class.new(1.0, 2.0, 3.0, 4.0)).not_to eq(QRect.new(1, 2, 3, 5))

    expect(described_class.new(1.0, 2.0, 3.0, 4.0)).not_to eq(1.0)
    expect(described_class.new(1.0, 2.0, 3.0, 4.0)).not_to eq(nil)
  end
end
