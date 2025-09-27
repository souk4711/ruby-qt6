RSpec.describe RubyQt6::QtCore::QSizeF do
  it "#initialize" do
    o = described_class.new(3, 7)
    expect(o.width).to eq(3)
    expect(o.height).to eq(7)
  end

  it "#==" do
    expect(described_class.new(3.0, 7.0)).to eq(described_class.new(3, 7))
    expect(described_class.new(3.0, 7.0)).to eq(RubyQt6::QtCore::QSize.new(3, 7))
    expect(described_class.new(3.0, 7.0)).not_to eq(described_class.new(3, 9))
    expect(described_class.new(3.0, 7.0)).not_to eq(RubyQt6::QtCore::QSizeF.new(3, 9))
  end
end
