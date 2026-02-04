RSpec.describe QUrl do
  it "#initialize" do
    o = described_class.new("https://github.com/souk4711/ruby-qt6/issues?q=is:issue state:open")
    expect(o.scheme).to eq("https")
    expect(o.host).to eq("github.com")
    expect(o.path).to eq("/souk4711/ruby-qt6/issues")
    expect(o.query).to eq("q=is:issue state:open")
  end

  it "#to_s" do
    o = described_class.new("https://github.com/souk4711/ruby-qt6/issues?q=is:issue state:open")
    expect(o.to_s).to eq("https://github.com/souk4711/ruby-qt6/issues?q=is:issue state:open")
  end
end
