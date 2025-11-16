RSpec.describe RubyQt6::QtCore::QVariantList do
  it "#initialize" do
    o = described_class.new
    expect(o.size).to eq(0)
    expect(o[0]).to be_nil
    expect(o[-1]).to be_nil
  end

  it "#to_a" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"
    a = o.to_a
    expect(a).to be_a(Array)
    expect(a[0]).to be_a(RubyQt6::QtCore::QVariant)
    expect(a[0].value).to eq("1")
    expect(a[-1].value).to eq("5")
  end

  it "#at" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"
    expect(o.at(-o.size - 1)).to be_nil
    expect(o.at(-o.size).value).to eq("1")
    expect(o.at(-1).value).to eq("5")
    expect(o.at(0).value).to eq("1")
    expect(o.at(1).value).to eq("2")
    expect(o.at(o.size - 1).value).to eq("5")
    expect(o.at(o.size)).to be_nil
  end

  it "#first" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"
    expect(o.first.value).to eq("1")

    o = described_class.new
    expect(o.first).to be_nil
  end

  it "#last" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"
    expect(o.last.value).to eq("5")

    o = described_class.new
    expect(o.last).to be_nil
  end

  it "#count" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"
    expect(o.count).to eq(5)
    expect(o.count("2")).to eq(2)
    expect(o.count("7")).to eq(0)
  end

  it "#include?" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"
    expect(o).to include("3")
    expect(o).not_to include("6")
  end

  it "#index" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"
    expect(o.index("3")).to eq(2)
    expect(o.index("6")).to be_nil
  end

  it "#insert" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"
    r = o.insert(0, "xyz")
    expect(o[0].value).to eq("xyz")
    expect(o.size).to eq(6)
    expect(o.object_id).to eq(r.object_id)

    o.insert(o.size, "...")
    expect(o[-1].value).to eq("...")
    expect(o.size).to eq(7)

    o.insert(-1, ">>>")
    expect(o[-1].value).to eq(">>>")
    expect(o.size).to eq(8)

    o.insert(-o.size, "~~~")
    expect(o[1].value).to eq("~~~")
    expect(o.size).to eq(9)

    o.insert(-o.size - 1, "<<<")
    expect(o[0].value).to eq("<<<")
    expect(o.size).to eq(10)

    expect { o.insert(-o.size - 2, "?") }.to raise_error(/index -12 too small for array; minimum: -11/)
  end

  it "#push" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"
    r = o.push("12345")
    expect(o[-1].value).to eq("12345")
    expect(o.size).to eq(6)
    expect(o.object_id).to eq(r.object_id)
  end

  it "#pop" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"
    expect(o.pop.value).to eq("5")
    expect(o[-1].value).to eq("2")
    expect(o.size).to eq(4)

    o = described_class.new
    expect(o.pop).to be_nil
  end

  it "#clear" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"
    r = o.clear
    expect(o.size).to eq(0)
    expect(o.object_id).to eq(r.object_id)
  end

  it "#delete" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"

    expect(o.delete("2").value).to eq("2")
    expect(o.size).to eq(3)

    expect(o.delete("7")).to be_nil
    expect(o.size).to eq(3)
  end

  it "#delete_at" do
    o = described_class.new << "1" << "2" << "3" << "4" << "5"

    expect(o.delete_at(0).value).to eq("1")
    expect(o[0].value).to eq("2")
    expect(o.size).to eq(4)

    expect(o.delete_at(o.size)).to be_nil
    expect(o[o.size]).to be_nil
    expect(o.size).to eq(4)

    expect(o.delete_at(-1).value).to eq("5")
    expect(o[-1].value).to eq("4")
    expect(o.size).to eq(3)

    expect(o.delete_at(-o.size).value).to eq("2")
    expect(o[-o.size].value).to eq("3")
    expect(o.size).to eq(2)
  end

  it "#[]=" do
    o = described_class.new << "1" << "2" << "3" << "2" << "5"

    o[0] = "<<<"
    expect(o[0].value).to eq("<<<")
    expect(o.size).to eq(5)

    o[o.size] = ">>>"
    expect(o[-1].value).to eq(">>>")
    expect(o.size).to eq(6)

    o[-1] = "+++"
    expect(o[-1].value).to eq("+++")
    expect(o.size).to eq(6)

    o[-o.size] = "---"
    expect(o[0].value).to eq("---")
    expect(o.size).to eq(6)

    expect { o[-o.size - 1] = "?" }.to raise_error(/index -7 too small for array; minimum: -6/)
  end
end
