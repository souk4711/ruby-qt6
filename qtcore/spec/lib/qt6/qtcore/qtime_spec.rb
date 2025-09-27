RSpec.describe RubyQt6::QtCore::QTime do
  it "#initialize" do
    o = described_class.new(12, 30, 45)
    expect(o.hour).to eq(12)
    expect(o.minute).to eq(30)
    expect(o.second).to eq(45)
    expect(o.msec).to eq(0)
  end

  it "#to_s" do
    o = described_class.new(12, 30, 45)
    expect(o.to_s).to eq("12:30:45")
  end

  it "#<=>" do
    expect(described_class.new(7, 7, 7)).to be < described_class.new(7, 7, 8)
    expect(described_class.new(7, 7, 7)).to be > described_class.new(7, 7, 6)
    expect(described_class.new(7, 7, 7)).to be == described_class.new(7, 7, 7)
    expect(described_class.new(7, 7, 7) <=> 7).to be_nil
    expect(described_class.new(7, 7, 7) <=> nil).to be_nil
  end
end
