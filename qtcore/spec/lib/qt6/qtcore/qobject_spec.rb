RSpec.describe QObject do
  describe ".q_object" do
    it "signal" do
      o = QObject.new
      expect(o.destroyed).to be_a(RubyQt6::QtCore::Private::Signal)

      metamethod = o.destroyed.instance_variable_get("@metamethod")
      expect(metamethod.qsignature).to eq("2destroyed(QObject*)")
    end
  end
end
