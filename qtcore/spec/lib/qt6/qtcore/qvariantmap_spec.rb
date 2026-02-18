RSpec.describe QVariantMap do
  it "#initialize" do
    o = described_class.new
    expect(o.size).to eq(0)
    expect(o["0"]).to be_nil
  end

  it "#has_key?" do
    o = described_class.new
    o["1"] = 1

    expect(o).to have_key("1")
    expect(o).not_to have_key("2")
  end

  it "#has_value?" do
    o = described_class.new
    o["1"] = 1

    expect(o).to have_value(1)
    expect(o).not_to have_value(2)
  end

  it "#insert" do
    o = described_class.new

    o["1"] = 1
    expect(o.size).to eq(1)
    expect(o["1"].value).to eq(1)

    o["2"] = 2
    expect(o.size).to eq(2)
    expect(o["2"].value).to eq(2)

    o["2"] = 3
    expect(o.size).to eq(2)
    expect(o["2"].value).to eq(3)
  end

  it "#delete" do
    o = described_class.new

    o["1"] = 1
    expect(o.size).to eq(1)
    expect(o["1"].value).to eq(1)

    o.delete("1")
    expect(o.size).to eq(0)
    expect(o["1"]).to be_nil
  end
end
