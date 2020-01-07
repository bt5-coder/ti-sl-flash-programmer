/*
* 函数名：			
Data_Frequency_Channel_Choose -RADIO 
* 参数：
* -无
* 返回值：
* -无
Data_frequency_map.Channel_Map[4]       40 通道 每8个通道一组，总共5组
*/
void Data_Frequency_Channel_Choose(void)
{
	Data_frequency_map.Current_unmappedChannel  = (Data_frequency_map.Last_UnmappedChannel + Data_frequency_map.Hop_Increment) % 37 ;
	//这里得到的是接下来的频率通道号，能不能用？需要和 MAP 进行比较
	Data_frequency_map.Last_UnmappedChannel  = Data_frequency_map.Current_unmappedChannel ; //上一次的频道等于当前频道
	while(1)
	{
		if (Data_frequency_map.Current_unmappedChannel < 8) //从第 0 个频道字节确定那个能用
		{
			if( (Data_frequency_map.Channel_Map[0] >> Data_frequency_map.Current_unmappedChannel)& 0x01 ) //如果这个频道是可用的
			{
				Data_frequency_map.Current_Frequency_value  = Data_frequency_map.Current_unmappedChannel ; 
				//得到真正的频率，可以直接赋值给 NRF_RADIO->FREQUENCY 寄存器
				break; // 找到了可用的频道 并计算得到了实际寄存器的频率值后跳出循环
			}
			else //这个频道不可用需要重新映射
			{
			Data_frequency_map.Current_unmappedChannel=Data_frequency_map.Used_Channels[Data_frequency_map.Current_unmappedChannel \
				% Data_frequency_map.Num_UsedChannels] ;
				//这里得到的是接下来的频率通道号，能不能用？需要和 MAP 进行比较
			}
		}
		else if(Data_frequency_map.Current_unmappedChannel < 16)//从第 1 个频道字节确定那个频道能用
		{
			if((Data_frequency_map.Channel_Map[1]  >> (Data_frequency_map.Current_unmappedChannel- 8)) & 0x01 ) //如果这个频道是可用的
			{
                                Data_frequency_map.Current_Frequency_value  = Data_frequency_map.Current_unmappedChannel ; 
				//得到真正的频率，可以直接赋值给 NRF_RADIO->FREQUENCY 寄存器

				break; // 找到了可用的频道并计算得到了实际寄存器的频率值后跳出循环
			}
			else //这个频道不可用需要重新映射
			{
			Data_frequency_map.Current_unmappedChannel=Data_frequency_map.Used_Channels[Data_frequency_map.Current_unmappedChannel \
				% Data_frequency_map.Num_UsedChannels] ;
				//这里得到的是接下来的频率通道号，能不能用？需要和 MAP 进行比较
			}
		}
		else if(Data_frequency_map.Current_unmappedChannel < 24) //从第 2 个频道字节确定那个频道能用
		{
			if((Data_frequency_map.Channel_Map[2]  >> (Data_frequency_map.Current_unmappedChannel-16)) & 0x01 ) //如果这个频道是可用的
			{
				Data_frequency_map.Current_Frequency_value  = Data_frequency_map.Current_unmappedChannel ; 
				//得到真正的频率，可以直接赋值给 NRF_RADIO->FREQUENCY 寄存器
				break; // 找到了可用的频道并计算得到了实际寄存器的频率值后跳出循环
			}
			else //这个频道不可用需要重新映射
			{
			Data_frequency_map.Current_unmappedChannel=Data_frequency_map.Used_Channels[Data_frequency_map.Current_unmappedChannel \
				% Data_frequency_map.Num_UsedChannels] ;
				//这里得到的是接下来的频率通道号，能不能用？需要和 MAP 进行比较
			}
		}
		else if(Data_frequency_map.Current_unmappedChannel < 32)//从第 3 个频道字节确定那个频道能用
		{
			if((Data_frequency_map.Channel_Map[3]  >>(Data_frequency_map.Current_unmappedChannel- 24)) & 0x01 ) //如果这个频道是可用的
			{
				Data_frequency_map.Current_Frequency_value  = Data_frequency_map.Current_unmappedChannel ; 
				//得到真正的频率，可以直接赋值给 NRF_RADIO->FREQUENCY 寄存器
				break; // 找到了可用的频道并计算得到了实际寄存器的频率值后跳出循环
			}
			else //这个频道不可用需要重新映射
			{
			Data_frequency_map.Current_unmappedChannel=Data_frequency_map.Used_Channels[Data_frequency_map.Current_unmappedChannel \
				% Data_frequency_map.Num_UsedChannels] ;
				//这里得到的是接下来的频率通道号，能不能用？需要和 MAP 进行比较
			}
		}
		else if(Data_frequency_map.Current_unmappedChannel < 40) //从第 4 个频道字节确定那个频道能用
		{
			if((Data_frequency_map.Channel_Map[4]  >>(Data_frequency_map.Current_unmappedChannel- 32)) & 0x01 ) //如果这个频道是可用的
			{
				Data_frequency_map.Current_Frequency_value  = Data_frequency_map.Current_unmappedChannel ; 
				//得到真正的频率，可以直接赋值给 NRF_RADIO->FREQUENCY 寄存器
				break; // 找到了可用的频道并计算得到了实际寄存器的频率值后跳出循环
			}
			else //这个频道不可用需要重新映射
			{
			Data_frequency_map.Current_unmappedChannel=Data_frequency_map.Used_Channels[Data_frequency_map.Current_unmappedChannel \
				% Data_frequency_map.Num_UsedChannels] ;
				//这里得到的是接下来的频率通道号，能不能用？需要和 MAP 进行比较
			}
		}
	}
	NRF_RADIO->FREQUENCY = Data_frequency_map.Current_Frequency_value; //Actual frequency (MHz): 2400 + register value

｝