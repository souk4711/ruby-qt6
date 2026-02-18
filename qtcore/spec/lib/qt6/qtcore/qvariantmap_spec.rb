RSpec.describe QVariantMap do
  it "#initialize" do
    o = described_class.new
    expect(o.size).to eq(0)
    expect(o["0"]).to be_nil
  end
end
