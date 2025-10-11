RSpec.describe RubyQt6::QtCore::QStringList do
  it "#initialize" do
    o = described_class.new
    expect(o.size).to eq(0)
    expect(o[0]).to be_nil
    expect(o[-1]).to be_nil

    o = described_class.new(2)
    expect(o.size).to eq(2)
    expect(o[0]).to eq("")
    expect(o[-1]).to eq("")

    o = described_class.new(4, "initial".to_qstr)
    expect(o.size).to eq(4)
    expect(o[0]).to eq("initial")
    expect(o[-1]).to eq("initial")
  end

  it "#resize" do
    o = described_class.new(4, "initial".to_qstr)
    expect(o.size).to eq(4)
    expect(o[0]).to eq("initial")
    expect(o[3]).to eq("initial")

    o.resize(8)
    expect(o.size).to eq(8)
    expect(o[3]).to eq("initial")
    expect(o[4]).to eq("")
    expect(o[7]).to eq("")

    o.resize(12, "resized".to_qstr)
    expect(o.size).to eq(12)
    expect(o[7]).to eq("")
    expect(o[8]).to eq("resized")
    expect(o[11]).to eq("resized")
  end

  it "#to_a" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"
    a = o.to_a
    expect(a).to be_a(Array)
    expect(a[0]).to be_a(RubyQt6::QtCore::QString)
    expect(a[0]).to eq("1")
    expect(a[-1]).to eq("5")
  end

  it "#to_ary" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"
    a = o.to_ary
    expect(a).to be_a(Array)
    expect(a[0]).to be_a(RubyQt6::QtCore::QString)
    expect(a[0]).to eq("1")
    expect(a[-1]).to eq("5")
  end

  it "#at" do
    [Array, described_class].each do |klass|
      o = klass.new << "1" << "2" << "3" << "2" << "5"
      expect(o.at(-o.size - 1)).to be_nil
      expect(o.at(-o.size)).to eq("1")
      expect(o.at(-1)).to eq("5")
      expect(o.at(0)).to eq("1")
      expect(o.at(1)).to eq("2")
      expect(o.at(o.size - 1)).to eq("5")
      expect(o.at(o.size)).to be_nil
    end
  end

  it "#first" do
    [Array, described_class].each do |klass|
      o = klass.new << "1" << "2" << "3" << "2" << "5"
      expect(o.first).to eq("1")

      o = klass.new
      expect(o.first).to be_nil
    end
  end

  it "#last" do
    [Array, described_class].each do |klass|
      o = klass.new << "1" << "2" << "3" << "2" << "5"
      expect(o.last).to eq("5")

      o = klass.new
      expect(o.last).to be_nil
    end
  end

  it "#count" do
    [Array, described_class].each do |klass|
      o = klass.new << "1" << "2" << "3" << "2" << "5"
      expect(o.count).to eq(5)
      expect(o.count("2")).to eq(2)
      expect(o.count("7")).to eq(0)
    end
  end

  it "#include?" do
    [Array, described_class].each do |klass|
      o = klass.new << "1" << "2" << "3" << "2" << "5"
      expect(o).to include("3")
      expect(o).not_to include("6")
    end
  end

  it "#index" do
    [Array, described_class].each do |klass|
      o = klass.new << "1" << "2" << "3" << "2" << "5"
      expect(o.index("3")).to eq(2)
      expect(o.index("6")).to be_nil
    end
  end

  it "#insert" do
    [Array, described_class].each do |klass|
      o = klass.new << "1" << "2" << "3" << "2" << "5"
      r = o.insert(0, "xyz")
      expect(o[0]).to eq("xyz")
      expect(o.size).to eq(6)
      expect(o.object_id).to eq(r.object_id)

      o.insert(o.size, "...")
      expect(o[-1]).to eq("...")
      expect(o.size).to eq(7)

      o.insert(-1, ">>>")
      expect(o[-1]).to eq(">>>")
      expect(o.size).to eq(8)

      o.insert(-o.size, "~~~")
      expect(o[1]).to eq("~~~")
      expect(o.size).to eq(9)

      o.insert(-o.size - 1, "<<<")
      expect(o[0]).to eq("<<<")
      expect(o.size).to eq(10)

      expect { o.insert(-o.size - 2, "?") }.to raise_error(/index -12 too small for array; minimum: -11/)
    end
  end

  it "#push" do
    [Array, described_class].each do |klass|
      o = klass.new << "1" << "2" << "3" << "2" << "5"
      r = o.push("12345")
      expect(o[-1]).to eq("12345")
      expect(o.size).to eq(6)
      expect(o.object_id).to eq(r.object_id)
    end
  end

  it "#pop" do
    [Array, described_class].each do |klass|
      o = klass.new << "1" << "2" << "3" << "2" << "5"
      expect(o.pop).to eq("5")
      expect(o[-1]).to eq("2")
      expect(o.size).to eq(4)

      o = klass.new
      expect(o.pop).to be_nil
    end
  end

  it "#clear" do
    [Array, described_class].each do |klass|
      o = klass.new << "1" << "2" << "3" << "2" << "5"
      r = o.clear
      expect(o.size).to eq(0)
      expect(o.object_id).to eq(r.object_id)
    end
  end

  it "#delete" do
    [Array, described_class].each do |klass|
      o = klass.new << "1" << "2" << "3" << "2" << "5"

      expect(o.delete("2")).to eq("2")
      expect(o.size).to eq(3)

      expect(o.delete("7")).to be_nil
      expect(o.size).to eq(3)
    end
  end

  it "#delete_at" do
    [Array, described_class].each do |klass|
      o = klass.new << "1" << "2" << "3" << "4" << "5"

      expect(o.delete_at(0)).to eq("1")
      expect(o[0]).to eq("2")
      expect(o.size).to eq(4)

      expect(o.delete_at(o.size)).to be_nil
      expect(o[o.size]).to be_nil
      expect(o.size).to eq(4)

      expect(o.delete_at(-1)).to eq("5")
      expect(o[-1]).to eq("4")
      expect(o.size).to eq(3)

      expect(o.delete_at(-o.size)).to eq("2")
      expect(o[-o.size]).to eq("3")
      expect(o.size).to eq(2)
    end
  end

  it "#[]=" do
    [Array, described_class].each do |klass|
      o = klass.new << "1" << "2" << "3" << "2" << "5"

      expect(o[0] = "<<<").to eq("<<<")
      expect(o[0]).to eq("<<<")
      expect(o.size).to eq(5)

      expect(o[o.size] = ">>>").to eq(">>>")
      expect(o[-1]).to eq(">>>")
      expect(o.size).to eq(6)

      expect(o[-1] = "+++").to eq("+++")
      expect(o[-1]).to eq("+++")
      expect(o.size).to eq(6)

      expect(o[-o.size] = "---").to eq("---")
      expect(o[0]).to eq("---")
      expect(o.size).to eq(6)

      expect { o[-o.size - 1] = "?" }.to raise_error(/index -7 too small for array; minimum: -6/)
    end
  end
end
