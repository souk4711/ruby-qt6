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

  it "#*" do
    o = described_class.new(1, 2) * 4
    expect(o).to be_a(described_class)
    expect(o.x).to eq(4)
    expect(o.y).to eq(8)

    o = described_class.new(1, 2) * 3.3
    expect(o).to be_a(described_class)
    expect(o.x).to eq(3)
    expect(o.y).to eq(7)
  end

  it "#+" do
    o = described_class.new(1, 2) + described_class.new(4, 7)
    expect(o).to be_a(described_class)
    expect(o.x).to eq(5)
    expect(o.y).to eq(9)
  end

  it "#-" do
    o = described_class.new(1, 2) - described_class.new(4, 7)
    expect(o).to be_a(described_class)
    expect(o.x).to eq(-3)
    expect(o.y).to eq(-5)
  end

  it "#/" do
    o = described_class.new(1, 2) / 3
    expect(o).to be_a(described_class)
    expect(o.x).to eq(0)
    expect(o.y).to eq(1)
  end

  it "#+@" do
    o1 = described_class.new(1, 2)
    o2 = + o1
    expect(o2).to be_a(described_class)
    expect(o1).to eq(o2)
    expect(o1.object_id).not_to eq(o2.object_id)
  end

  it "#-@" do
    o = - described_class.new(1, 2)
    expect(o).to be_a(described_class)
    expect(o.x).to eq(-1)
    expect(o.y).to eq(-2)
  end
end
