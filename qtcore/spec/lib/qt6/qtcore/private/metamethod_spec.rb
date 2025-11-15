RSpec.describe RubyQt6::QtCore::Private::MetaMethod do
  it "#initialize" do
    ["dateChanged(QDate)", "date_changed(QDate)"].each do |signature|
      o = described_class.new(signature, :signal, :libQt6)
      expect(o.signal?).to eq(true)
      expect(o.name).to eq("date_changed")
      expect(o.parameters).to eq(["QDate"])
      expect(o.signature).to eq("date_changed(QDate)")
      expect(o.return_type).to be_nil
      expect(o.qsignature).to eq("2dateChanged(QDate)")

      o = described_class.new(signature, :signal, :ruby)
      expect(o.signal?).to eq(true)
      expect(o.name).to eq("date_changed")
      expect(o.parameters).to eq(["QDate"])
      expect(o.signature).to eq("date_changed(QDate)")
      expect(o.return_type).to be_nil
      expect(o.qsignature).to eq("2date_changed(QDate)")
    end
  end
end
