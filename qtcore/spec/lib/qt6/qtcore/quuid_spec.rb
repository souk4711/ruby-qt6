RSpec.describe QUuid do
  it "#initialize" do
    o = described_class.new("774a1506-d835-4cee-ba86-5b316f6fc762")
    expect(o).to be_a(QUuid)
  end

  it "#to_s" do
    o = described_class.new("774a1506-d835-4cee-ba86-5b316f6fc762")
    expect(o.to_s).to eq("774a1506-d835-4cee-ba86-5b316f6fc762")
  end

  it "#<=>" do
    expect(described_class.new("774a1506-d835-4cee-ba86-5b316f6fc762")).to eq(described_class.new("774a1506-d835-4cee-ba86-5b316f6fc762"))
    expect(described_class.new("774a1506-d835-4cee-ba86-5b316f6fc762")).not_to eq(described_class.new("974a1506-d835-4cee-ba86-5b316f6fc762"))
    expect(described_class.new("774a1506-d835-4cee-ba86-5b316f6fc762") <=> "????").to be_nil
    expect(described_class.new("774a1506-d835-4cee-ba86-5b316f6fc762") <=> nil).to be_nil
  end
end
