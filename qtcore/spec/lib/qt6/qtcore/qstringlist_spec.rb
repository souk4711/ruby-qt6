RSpec.describe RubyQt6::QtCore::QStringList do
  let(:list_a) { described_class.new << "1" << "2" << "3" << "2" << "5" }
  let(:list_e) { described_class.new }

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

  it "#at" do
    expect(list_a.at(0)).to eq("1")
    expect(list_a.at(1)).to eq("2")
    expect(list_a.at(-1)).to eq("5")
    expect(list_a.at(list_a.size)).to be_nil
  end

  it "#first" do
    expect(list_a.first).to eq("1")
    expect(list_e.first).to be_nil
  end

  it "#last" do
    expect(list_a.last).to eq("5")
    expect(list_e.last).to be_nil
  end

  it "#count" do
    expect(list_a.count).to eq(5)
    expect(list_a.count("2")).to eq(2)
    expect(list_a.count("7")).to eq(0)
  end

  it "#include?" do
    expect(list_a).to include("3")
    expect(list_a).not_to include("6")
  end

  it "#index" do
    expect(list_a.index("3")).to eq(2)
    expect(list_a.index("6")).to be_nil
  end

  it "#insert" do
    r = list_a.insert(0, "xyz")
    expect(r).to be_a(described_class)
    expect(list_a[0]).to eq("xyz")

    list_a.insert(list_a.size, "...")
    expect(list_a[-1]).to eq("...")

    expect { list_e.dup.insert(0, "ok") }.not_to raise_error
    expect { list_e.dup.insert(1, "err") }.to raise_error(/Invalid index: 1/)
  end

  it "#push" do
    r = list_a.push("12345")
    expect(r).to be_a(described_class)
    expect(list_a[-1]).to eq("12345")
  end

  it "#pop" do
    expect(list_a.pop).to eq("5")
    expect(list_a[-1]).to eq("2")

    expect(list_e.pop).to be_nil
  end

  it "#clear" do
    r = list_a.clear
    expect(r).to be_a(described_class)
    expect(list_a.size).to eq(0)
  end

  it "#delete" do
    expect(list_a.delete("2")).to eq("2")
    expect(list_a.size).to eq(3)

    expect(list_a.delete("7")).to be_nil
  end

  it "#delete_at" do
    expect(list_a.delete_at(0)).to eq("1")
    expect(list_a.first).to eq("2")

    expect(list_a.delete_at(-1)).to eq("5")
    expect(list_a.last).to eq("2")

    expect(list_a.delete_at(list_a.size)).to be_nil
  end

  it "#[]=" do
    expect(list_a[0] = "xyz").to eq("xyz")
    expect(list_a.first).to eq("xyz")

    expect(list_a[-1] = "..").to eq("..")
    expect(list_a.last).to eq("..")

    expect { list_e[0] = "err" }.to raise_error(/Invalid index: 0/)
  end
end
