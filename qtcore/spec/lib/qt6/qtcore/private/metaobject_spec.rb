RSpec.describe RubyQt6::QtCore::Private::MetaObject do
  let(:receiver) { RubyQt6::QtCore::QObject }
  let(:signal) { RubyQt6::QtCore::Private::MetaMethod.new("signal()", :signal, :ruby) }
  let(:signal_qstr) { RubyQt6::QtCore::Private::MetaMethod.new("signal(QString)", :signal, :ruby) }
  let(:signal_qobj) { RubyQt6::QtCore::Private::MetaMethod.new("signal(QObject*)", :signal, :ruby) }

  describe ".find_receiver_metamethod" do
    it "type - signal" do
      metamethod = described_class.find_receiver_metamethod!(receiver, :destroyed, signal)
      expect(metamethod.type).to eq(:signal)
      expect(metamethod.qsignature).to eq("2destroyed()")
    end

    it "type - slot" do
      metamethod = described_class.find_receiver_metamethod!(receiver, :deleteLater, signal)
      expect(metamethod.type).to eq(:slot)
      expect(metamethod.qsignature).to eq("1deleteLater()")
    end

    it "receiver - class" do
      metamethod = described_class.find_receiver_metamethod!(RubyQt6::QtCore::QObject, :destroyed, signal)
      expect(metamethod.qsignature).to eq("2destroyed()")
    end

    it "receiver - instance" do
      metamethod = described_class.find_receiver_metamethod!(RubyQt6::QtCore::QObject.new, :destroyed, signal)
      expect(metamethod.qsignature).to eq("2destroyed()")
    end

    it "match - ignore upcase/downcase" do
      [:deleteLater, :delete_later, "deleteLater", "delete_later"].each do |method|
        metamethod = described_class.find_receiver_metamethod!(receiver, method, signal)
        expect(metamethod.qsignature).to eq("1deleteLater()")
      end
    end

    it "match - best match" do
      metamethod = described_class.find_receiver_metamethod!(receiver, :destroyed, nil)
      expect(metamethod.qsignature).to eq("2destroyed()")

      metamethod = described_class.find_receiver_metamethod!(receiver, :destroyed, signal)
      expect(metamethod.qsignature).to eq("2destroyed()")

      metamethod = described_class.find_receiver_metamethod!(receiver, :destroyed, signal_qstr)
      expect(metamethod.qsignature).to eq("2destroyed()")

      metamethod = described_class.find_receiver_metamethod!(receiver, :destroyed, signal_qobj)
      expect(metamethod.qsignature).to eq("2destroyed(QObject*)")
    end

    it "exception - no sunch method" do
      expect { described_class.find_receiver_metamethod!(receiver, :destroyed, signal) }.not_to raise_error
      expect { described_class.find_receiver_metamethod!(receiver, :noSuchMethod, signal) }.to raise_error(/No compatible metamethod: QObject#no_such_method/)
    end

    it "exception - too few arguments" do
      expect { described_class.find_receiver_metamethod!(receiver, :objectNameChanged, signal_qstr) }.not_to raise_error
      expect { described_class.find_receiver_metamethod!(receiver, :objectNameChanged, signal) }.to raise_error(/No compatible metamethod: QObject#object_name_changed/)
    end

    it "exception - wrong argument type" do
      expect { described_class.find_receiver_metamethod!(receiver, :objectNameChanged, signal_qstr) }.not_to raise_error
      expect { described_class.find_receiver_metamethod!(receiver, :objectNameChanged, signal_qobj) }.to raise_error(/No compatible metamethod: QObject#object_name_changed/)
    end
  end
end
