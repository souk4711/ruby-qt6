RSpec.describe RubyQt6::QtCore::QBool do
  it "#initialize" do
    o = described_class.new
    expect(o.value).to be_nil

    o = described_class.new(false)
    expect(o.value).to eq(false)

    o = described_class.new(true)
    expect(o.value).to eq(true)
  end

  it "#ok?" do
    o = described_class.new
    expect(o.ok?).to eq(false)

    o = described_class.new(false)
    expect(o.ok?).to eq(false)

    o = described_class.new(true)
    expect(o.ok?).to eq(true)
  end
end
