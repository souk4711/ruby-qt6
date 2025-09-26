RSpec.describe RubyQt6::QtCore::QString do
  it "#initialize" do
    o = described_class.new("ハロー")
    expect(o).to eq("ハロー")
  end

  it "#to_str" do
    o = described_class.new("ワールド")
    expect("ハロー・" + o).to eq("ハロー・ワールド")
  end

  it "#==" do
    o = described_class.new("foo")
    expect(o == "foo").to be_truthy
    expect(o == "food").to be_falsy
    expect(o == "FOO").to be_falsy
  end

  it "#===" do
    o = described_class.new("foo")
    expect(o === "foo").to be_truthy
    expect(o === "food").to be_falsy
    expect(o === "FOO").to be_falsy
  end
end
