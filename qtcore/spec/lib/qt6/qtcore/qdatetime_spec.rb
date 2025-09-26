RSpec.describe RubyQt6::QtCore::QDateTime do
  it "#initialize" do
    date = RubyQt6::QtCore::QDate.new(1777, 7, 7)
    time = RubyQt6::QtCore::QTime.new(7, 7, 7)
    o = described_class.new(date, time)
    expect(o.date).to eq(date)
    expect(o.time).to eq(time)
  end

  it "#to_s" do
    date = RubyQt6::QtCore::QDate.new(1777, 7, 7)
    time = RubyQt6::QtCore::QTime.new(7, 7, 7)
    o = described_class.new(date, time)
    expect(o.to_s).to eq("07 Jul 1777 07:07:07 +0736")
  end

  it "#<=>" do
    date = RubyQt6::QtCore::QDate.new(1777, 7, 7)
    time = RubyQt6::QtCore::QTime.new(7, 7, 7)
    expect(described_class.new(date, time)).to be < described_class.new(date, time).add_msecs(+7)
    expect(described_class.new(date, time)).to be > described_class.new(date, time).add_msecs(-7)
    expect(described_class.new(date, time)).to be == described_class.new(date, time)
    expect(described_class.new(date, time) <=> 7777).to be_nil
  end
end
