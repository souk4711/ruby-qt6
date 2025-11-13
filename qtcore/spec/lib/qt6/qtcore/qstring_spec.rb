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

  it "#downcase" do
    [String, described_class].each do |klass|
      o = klass.new("hEllO")
      expect(o.downcase).to eq("hello")

      o = klass.new("The Qt PROJECT")
      expect(o.downcase).to eq("the qt project")
    end
  end

  it "#upcase" do
    [String, described_class].each do |klass|
      o = klass.new("hEllO")
      expect(o.upcase).to eq("HELLO")

      o = klass.new("TeXt")
      expect(o.upcase).to eq("TEXT")
    end
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

  it "#[]" do
    [String, described_class].each do |klass|
      o = klass.new("abc")
      expect(o[-4]).to eq(nil)
      expect(o[-3]).to eq("a")
      expect(o[-2]).to eq("b")
      expect(o[-1]).to eq("c")
      expect(o[0]).to eq("a")
      expect(o[1]).to eq("b")
      expect(o[2]).to eq("c")
      expect(o[3]).to eq(nil)
      expect(o[1, -1]).to eq(nil)
      expect(o[1, 0]).to eq("")
      expect(o[1, 1]).to eq("b")
      expect(o[1, 2]).to eq("bc")
      expect(o[1, 3]).to eq("bc")
    end
  end

  it "#[]=" do
    [String, described_class].each do |klass|
      o = klass.new("abc")
      expect(o[1] = "xyz").to eq("xyz")
      expect(o).to eq("axyzc")

      o = klass.new("abc")
      expect(o[-1] = "xyz").to eq("xyz")
      expect(o).to eq("abxyz")

      o = klass.new("abc")
      expect { o[4] = "xyz" }.to raise_error("index 4 out of string")
      expect { o[-4] = "xyz" }.to raise_error("index -4 out of string")

      o = klass.new("")
      expect(o[0] = "xyz").to eq("xyz")
      expect(o).to eq("xyz")

      o = klass.new("")
      expect { o[1] = "xyz" }.to raise_error("index 1 out of string")
      expect { o[-1] = "xyz" }.to raise_error("index -1 out of string")
    end
  end

  it "#index" do
    [String, described_class].each do |klass|
      o = klass.new("foo")
      expect(o.index("f")).to eq(0)
      expect(o.index("o")).to eq(1)
      expect(o.index("oo")).to eq(1)
      expect(o.index("ooo")).to eq(nil)

      o = klass.new("foo")
      expect(o.index("o", 1)).to eq(1)
      expect(o.index("o", 2)).to eq(2)
      expect(o.index("o", 3)).to eq(nil)

      o = klass.new("foo")
      expect(o.index("o", -1)).to eq(2)
      expect(o.index("o", -2)).to eq(1)
      expect(o.index("o", -3)).to eq(1)
      expect(o.index("o", -4)).to eq(nil)
    end
  end
end
