RSpec.describe RubyQt6::QtCore::QString do
  it "#initialize" do
    o = described_class.new("ハロー")
    expect(o).to eq("ハロー")
  end

  it "#to_s" do
    o = described_class.new("ワールド")
    s = o.to_s
    expect(s).to be_a(String)
    expect(s).to eq("ワールド")
  end

  it "#to_str" do
    o = described_class.new("ワールド")
    s = o.to_str
    expect(s).to be_a(String)
    expect(s).to eq("ワールド")
  end

  it "#<=>" do
    expect(described_class.new("foo") <=> "foo").to eq(0)
    expect(described_class.new("foo") <=> "food").to eq(-1)
    expect(described_class.new("food") <=> "foo").to eq(1)
    expect(described_class.new("FOO") <=> "foo").to eq(-1)
    expect(described_class.new("foo") <=> "FOO").to eq(1)
    expect(described_class.new("foo") <=> 1).to eq(nil)
    expect(described_class.new("foo") <=> nil).to eq(nil)
  end

  it "[]=" do
    o = described_class.new("abc")
    expect(o[1] = "BD").to eq("BD")
    expect(o).to eq("aBDc")

    o = described_class.new("abc")
    expect { o[o.size + 1] = "BD" }.to raise_error("index 4 out of string")
  end
end
