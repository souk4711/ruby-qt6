RSpec.describe RubyQt6::QtCore::QString do
  it "#initialize" do
    o = described_class.new("ハロー")
    expect(o).to eq("ハロー")
  end

  it "#to_str" do
    o = described_class.new("ワールド")
    expect("ハロー・" + o).to eq("ハロー・ワールド")
  end

  it "#<=>" do
    ["foo", "food", "FOO", 1, nil].each do |other|
      rstr = "foo"
      qstr = described_class.new(rstr)
      expect(qstr <=> other).to eq(rstr <=> other)
    end
  end
end
