# frozen_string_literal: true

class AudioInfo
  def initialize(format)
    @m_format = format
    @m_level = 0.0
  end

  def calculate_level(data, length)
    channel_bytes = @m_format.bytes_per_sample
    sample_bytes = @m_format.bytes_per_frame
    num_samples = (length / sample_bytes).to_i

    max_value = 0.0
    m_offset = 0

    num_samples.times do
      @m_format.channel_count.times do
        value = 0.0
        if data.length > m_offset
          data_sample = data[m_offset, data.length - m_offset]
          value = @m_format.normalized_sample_value(data_sample)
        end
        max_value = [value, max_value].max
        m_offset += channel_bytes
      end
    end

    max_value
  end
end
