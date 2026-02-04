RSpec.describe QSize do
  it "#initialize" do
    o = described_class.new(3, 7)
    expect(o.width).to eq(3)
    expect(o.height).to eq(7)

    o = described_class.new(3, 7.0)
    expect(o.width).to eq(3)
    expect(o.height).to eq(7)
  end

  it "#==" do
    expect(described_class.new(3, 7)).to eq(described_class.new(3, 7))
    expect(described_class.new(3, 7)).not_to eq(described_class.new(3, 8))

    expect(described_class.new(3, 7)).to eq(QSizeF.new(3.0, 7.0))
    expect(described_class.new(3, 7)).not_to eq(QSizeF.new(3.0, 7.1))

    expect(described_class.new(3, 7)).not_to eq(3)
    expect(described_class.new(3, 7)).not_to eq(nil)
  end
end
