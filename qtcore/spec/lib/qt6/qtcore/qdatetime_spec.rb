RSpec.describe QDateTime do
  it "#initialize" do
    date = QDate.new(1777, 7, 7)
    time = QTime.new(7, 7, 7)
    o = described_class.new(date, time)
    expect(o.date).to eq(date)
    expect(o.time).to eq(time)
  end

  it "#to_s" do
    date = QDate.new(1777, 7, 7)
    time = QTime.new(7, 7, 7)
    o = described_class.new(date, time)
    expect(o.to_s).to eq("07 Jul 1777 07:07:07 +0736")
  end

  it "#<=>" do
    date = QDate.new(1777, 7, 7)
    time = QTime.new(7, 7, 7)
    expect(described_class.new(date, time)).to be < described_class.new(date, time).add_msecs(+7)
    expect(described_class.new(date, time)).to be > described_class.new(date, time).add_msecs(-7)
    expect(described_class.new(date, time)).to be == described_class.new(date, time)
    expect(described_class.new(date, time) <=> 7777).to be_nil
    expect(described_class.new(date, time) <=> nil).to be_nil
  end
end
