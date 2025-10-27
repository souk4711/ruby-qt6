RSpec.describe RubyQt6::QtDBus::QDBusReply do
  describe "#initialize" do
    it "error" do
      message = RubyQt6::QtDBus::QDBusMessage.create_error(RubyQt6::QtDBus::QDBusError::UnknownMethod, "No such method 'ping' in any interface at object path '/' (signature 's')".to_qstr)
      o = described_class.new(message)
      expect(o.valid?).to eq(false)
      expect(o.error.type).to eq(RubyQt6::QtDBus::QDBusError::UnknownMethod)
      expect(o.value).to be_nil
    end

    it "ok" do
      message = RubyQt6::QtDBus::QDBusMessage.new
      message.set_arguments("pong!")
      o = described_class.new(message)
      expect(o.valid?).to eq(true)
      expect(o.error.type).to eq(RubyQt6::QtDBus::QDBusError::NoError)
      expect(o.value).to eq("pong!")
    end
  end
end
