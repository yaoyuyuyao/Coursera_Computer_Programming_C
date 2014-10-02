# This program is trying to borrow completed ph1 data for Bayesian sample size of a new PK study
# Taking AUClast as example

oldwd<-getwd() #save your old working directory
setwd("H:\\Biosimilars\\ABP 501\\Japanese BE study\\Bayesian Japanese sample size calculation\\") #change your working directory


# Analyze ph1 AUCinf data to get prior
ph1=read.table("20110217_AUCinfall.txt", header = TRUE)

oldlogauc=log(ph1[,2])
oldt=ph1[,3]
oldweight=log(ph1[,4])
meanweight=mean(oldweight)
sdweight=sd(oldweight)

fit=lm(oldlogauc~oldt+oldweight)
coef=summary(fit)$coefficients[2,1] 
err=summary(fit)$coefficients[2,2] 
CI2=coef + c(-1,1)*err*qt(0.95, length(oldlogauc)-2)


set.seed(79843)
equiv=rep(0,40)
equiv1=rep(0,40)
for(j in 1:40){
N <- j+15
t <- rep(0:1, c(N, N))
weight=rnorm(2*N,meanweight,sdweight)

for (i in 1:1000){
truebeta1 <- rnorm(1, mean=11.06, sd=0.25) 	
truebeta2=0
truebeta3=-0.82

# Generate fake data from true parameters
logauc <- rep(0,2*N)
logauc[1:N] <- rnorm(N, mean=truebeta1+truebeta3*weight[1:N], sd=sqrt(log(0.4^2+1)) )		
logauc[(N+1):(2*N)] <- rnorm(N, mean=(truebeta1+truebeta2+truebeta3*weight[(N+1):(2*N)]), sd=sqrt(log(0.4^2+1)) )


newlogauc=c(oldlogauc,logauc)
newt=c(oldt,t)
newweight=c(oldweight,weight)

#fit=lm(logauc~t+weight)
#coef=summary(fit)$coefficients[2,1] 
#err=summary(fit)$coefficients[2,2]
#CI=coef + c(-1,1)*err*qt(0.95, length(logauc)-2)
#equiv[j]=equiv[j]+(CI[1]>=log(0.8))*(CI[2]<=log(1.25)) 
fit1=lm(newlogauc~newt+newweight)
coef1=summary(fit1)$coefficients[2,1] 
err1=summary(fit1)$coefficients[2,2] 
CI1=coef1+ c(-1,1)*err1*qt(0.95, length(newlogauc)-2)
equiv1[j]=equiv1[j]+(CI1[1]>=log(0.8))*(CI1[2]<=log(1.25))
}
if(equiv1[j]>900) break 
}
print((min(which(equiv1>900))+15)/0.9)