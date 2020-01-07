/*
* ��������			
Data_Frequency_Channel_Choose -RADIO 
* ������
* -��
* ����ֵ��
* -��
Data_frequency_map.Channel_Map[4]       40 ͨ�� ÿ8��ͨ��һ�飬�ܹ�5��
*/
void Data_Frequency_Channel_Choose(void)
{
	Data_frequency_map.Current_unmappedChannel  = (Data_frequency_map.Last_UnmappedChannel + Data_frequency_map.Hop_Increment) % 37 ;
	//����õ����ǽ�������Ƶ��ͨ���ţ��ܲ����ã���Ҫ�� MAP ���бȽ�
	Data_frequency_map.Last_UnmappedChannel  = Data_frequency_map.Current_unmappedChannel ; //��һ�ε�Ƶ�����ڵ�ǰƵ��
	while(1)
	{
		if (Data_frequency_map.Current_unmappedChannel < 8) //�ӵ� 0 ��Ƶ���ֽ�ȷ���Ǹ�����
		{
			if( (Data_frequency_map.Channel_Map[0] >> Data_frequency_map.Current_unmappedChannel)& 0x01 ) //������Ƶ���ǿ��õ�
			{
				Data_frequency_map.Current_Frequency_value  = Data_frequency_map.Current_unmappedChannel ; 
				//�õ�������Ƶ�ʣ�����ֱ�Ӹ�ֵ�� NRF_RADIO->FREQUENCY �Ĵ���
				break; // �ҵ��˿��õ�Ƶ�� ������õ���ʵ�ʼĴ�����Ƶ��ֵ������ѭ��
			}
			else //���Ƶ����������Ҫ����ӳ��
			{
			Data_frequency_map.Current_unmappedChannel=Data_frequency_map.Used_Channels[Data_frequency_map.Current_unmappedChannel \
				% Data_frequency_map.Num_UsedChannels] ;
				//����õ����ǽ�������Ƶ��ͨ���ţ��ܲ����ã���Ҫ�� MAP ���бȽ�
			}
		}
		else if(Data_frequency_map.Current_unmappedChannel < 16)//�ӵ� 1 ��Ƶ���ֽ�ȷ���Ǹ�Ƶ������
		{
			if((Data_frequency_map.Channel_Map[1]  >> (Data_frequency_map.Current_unmappedChannel- 8)) & 0x01 ) //������Ƶ���ǿ��õ�
			{
                                Data_frequency_map.Current_Frequency_value  = Data_frequency_map.Current_unmappedChannel ; 
				//�õ�������Ƶ�ʣ�����ֱ�Ӹ�ֵ�� NRF_RADIO->FREQUENCY �Ĵ���

				break; // �ҵ��˿��õ�Ƶ��������õ���ʵ�ʼĴ�����Ƶ��ֵ������ѭ��
			}
			else //���Ƶ����������Ҫ����ӳ��
			{
			Data_frequency_map.Current_unmappedChannel=Data_frequency_map.Used_Channels[Data_frequency_map.Current_unmappedChannel \
				% Data_frequency_map.Num_UsedChannels] ;
				//����õ����ǽ�������Ƶ��ͨ���ţ��ܲ����ã���Ҫ�� MAP ���бȽ�
			}
		}
		else if(Data_frequency_map.Current_unmappedChannel < 24) //�ӵ� 2 ��Ƶ���ֽ�ȷ���Ǹ�Ƶ������
		{
			if((Data_frequency_map.Channel_Map[2]  >> (Data_frequency_map.Current_unmappedChannel-16)) & 0x01 ) //������Ƶ���ǿ��õ�
			{
				Data_frequency_map.Current_Frequency_value  = Data_frequency_map.Current_unmappedChannel ; 
				//�õ�������Ƶ�ʣ�����ֱ�Ӹ�ֵ�� NRF_RADIO->FREQUENCY �Ĵ���
				break; // �ҵ��˿��õ�Ƶ��������õ���ʵ�ʼĴ�����Ƶ��ֵ������ѭ��
			}
			else //���Ƶ����������Ҫ����ӳ��
			{
			Data_frequency_map.Current_unmappedChannel=Data_frequency_map.Used_Channels[Data_frequency_map.Current_unmappedChannel \
				% Data_frequency_map.Num_UsedChannels] ;
				//����õ����ǽ�������Ƶ��ͨ���ţ��ܲ����ã���Ҫ�� MAP ���бȽ�
			}
		}
		else if(Data_frequency_map.Current_unmappedChannel < 32)//�ӵ� 3 ��Ƶ���ֽ�ȷ���Ǹ�Ƶ������
		{
			if((Data_frequency_map.Channel_Map[3]  >>(Data_frequency_map.Current_unmappedChannel- 24)) & 0x01 ) //������Ƶ���ǿ��õ�
			{
				Data_frequency_map.Current_Frequency_value  = Data_frequency_map.Current_unmappedChannel ; 
				//�õ�������Ƶ�ʣ�����ֱ�Ӹ�ֵ�� NRF_RADIO->FREQUENCY �Ĵ���
				break; // �ҵ��˿��õ�Ƶ��������õ���ʵ�ʼĴ�����Ƶ��ֵ������ѭ��
			}
			else //���Ƶ����������Ҫ����ӳ��
			{
			Data_frequency_map.Current_unmappedChannel=Data_frequency_map.Used_Channels[Data_frequency_map.Current_unmappedChannel \
				% Data_frequency_map.Num_UsedChannels] ;
				//����õ����ǽ�������Ƶ��ͨ���ţ��ܲ����ã���Ҫ�� MAP ���бȽ�
			}
		}
		else if(Data_frequency_map.Current_unmappedChannel < 40) //�ӵ� 4 ��Ƶ���ֽ�ȷ���Ǹ�Ƶ������
		{
			if((Data_frequency_map.Channel_Map[4]  >>(Data_frequency_map.Current_unmappedChannel- 32)) & 0x01 ) //������Ƶ���ǿ��õ�
			{
				Data_frequency_map.Current_Frequency_value  = Data_frequency_map.Current_unmappedChannel ; 
				//�õ�������Ƶ�ʣ�����ֱ�Ӹ�ֵ�� NRF_RADIO->FREQUENCY �Ĵ���
				break; // �ҵ��˿��õ�Ƶ��������õ���ʵ�ʼĴ�����Ƶ��ֵ������ѭ��
			}
			else //���Ƶ����������Ҫ����ӳ��
			{
			Data_frequency_map.Current_unmappedChannel=Data_frequency_map.Used_Channels[Data_frequency_map.Current_unmappedChannel \
				% Data_frequency_map.Num_UsedChannels] ;
				//����õ����ǽ�������Ƶ��ͨ���ţ��ܲ����ã���Ҫ�� MAP ���бȽ�
			}
		}
	}
	NRF_RADIO->FREQUENCY = Data_frequency_map.Current_Frequency_value; //Actual frequency (MHz): 2400 + register value

��