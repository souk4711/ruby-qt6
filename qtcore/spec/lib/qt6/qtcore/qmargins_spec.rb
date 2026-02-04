RSpec.describe QMargins do
  it "#initialize" do
    o = described_class.new(1, 2, 3, 4)
    expect(o.left).to eq(1)
    expect(o.top).to eq(2)
    expect(o.right).to eq(3)
    expect(o.bottom).to eq(4)

    o = described_class.new(1, 2, 3.0, 4.0)
    expect(o.left).to eq(1)
    expect(o.top).to eq(2)
    expect(o.right).to eq(3)
    expect(o.bottom).to eq(4)
  end

  it "#==" do
    expect(described_class.new(1, 2, 3, 4)).to eq(described_class.new(1, 2, 3, 4))
    expect(described_class.new(1, 2, 3, 4)).not_to eq(described_class.new(1, 2, 3, 5))

    expect(described_class.new(1, 2, 3, 4)).to eq(QMarginsF.new(1.0, 2.0, 3.0, 4.0))
    expect(described_class.new(1, 2, 3, 4)).not_to eq(QMarginsF.new(1.0, 2.0, 3.0, 4.1))

    expect(described_class.new(1, 2, 3, 4)).not_to eq(1)
    expect(described_class.new(1, 2, 3, 4)).not_to eq(nil)
  end
end
