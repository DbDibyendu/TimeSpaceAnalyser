import tsanalyser
tsanalyser.getTSAnlaysis()
ram = tsanalyser.getCurrentRSS()

print(ram)

tsanalyser.startKeepingTime()

time = tsanalyser.getTimeTaken()

print(time)
