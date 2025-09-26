RSpec.describe RubyQt6::QtCore::QString do
  it "#initialize" do
    o = described_class.new("ハロー")
    expect(o).to eq("ハロー")
  end

  it "#to_s" do
    o = described_class.new("ワールド")
    expect(o.to_s).to eq("ワールド")
  end

  it "#to_str" do
    o = described_class.new("ワールド")
    expect("ハロー・" + o).to eq("ハロー・ワールド")
  end

  it "#<=>" do
    expect(described_class.new("foo") <=> "foo").to eq(0)
    expect(described_class.new("foo") <=> "food").to eq(-1)
    expect(described_class.new("food") <=> "foo").to eq(1)
    expect(described_class.new("FOO") <=> "foo").to eq(-1)
    expect(described_class.new("foo") <=> "FOO").to eq(1)
    expect(described_class.new("foo") <=> 1).to eq(nil)
  end
end
